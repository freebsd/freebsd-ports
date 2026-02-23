PORTNAME=	alloy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.1
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	zach.leslie@grafana.com
COMMENT=	OpenTelemetry Collector distribution with programmable pipelines
WWW=		https://github.com/grafana/alloy

LICENSE=	MIT

# no_targets: we supply do-build/do-install (build from tarball); avoids duplicate target warnings.
USES=		go:modules,no_targets

# nodefault: go.mk sets WRKSRC for the module zip; avoid USE_GITHUB+WRKSRC sanity warning.
USE_GITHUB=	yes,nodefault
GH_ACCOUNT=	grafana
GH_PROJECT=	alloy

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-install

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
# Main alloy binary is built from ./collector (single main package).
# Use relative path so -mod=vendor treats it as main module, not an external import.
GO_TARGET=	./collector
GO_BUILDFLAGS=	-ldflags='-X github.com/grafana/alloy/internal/build.Version=${GH_TAGNAME}'

# Run before go-post-extract (800) so go mod tidy sees replace ./syntax and ./collector.
_USES_extract+=	700:alloy-pre-go-extract
alloy-pre-go-extract:
	${CP} -r ${WRKDIR}/${PORTNAME}-${DISTVERSION}/syntax ${GO_WRKSRC}
	${CP} -r ${WRKDIR}/${PORTNAME}-${DISTVERSION}/collector ${GO_WRKSRC}
	${CP} -r ${WRKDIR}/${PORTNAME}-${DISTVERSION}/extension ${GO_WRKSRC}

post-fetch:
	@${ECHO_MSG} "===> Fetching ${GO_MODNAME}/syntax dependency"
	(cd ${DISTDIR}/${DIST_SUBDIR}; [ -e syntax/go.mod ] || (\
		${MKDIR} syntax; \
		${TAR} -xzf ${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-${DISTVERSION}/syntax/go.mod; \
		${CP} ${PORTNAME}-${DISTVERSION}/syntax/go.mod syntax/go.mod))


# Copy main module vendor into tarball after go-post-extract (800). Collector submodule is built with -mod=mod.
_USES_extract+=	900:alloy-post-go-extract
alloy-post-go-extract:
	@if [ -d ${GO_WRKSRC}/vendor ]; then \
		${CP} -r ${GO_WRKSRC}/vendor ${WRKDIR}/${PORTNAME}-${DISTVERSION}/; \
	else \
		${ECHO_MSG} "===> WARNING: ${GO_WRKSRC}/vendor missing (go mod vendor may have failed)"; \
	fi

# Define before .include so bsd.port.mk and go.mk see !target(do-build/do-install) and do not add defaults.
_GO_WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
# Collector is a Go submodule (own go.mod with replace directives); use -mod=mod so Go uses cache/parent, not vendor.
do-build:
	(cd ${_GO_WRKSRC}/collector; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} \
		GOPROXY=${GO_GOPROXY} \
		${GO_CMD} build ${GO_BUILDFLAGS} -mod=mod -o ${GO_WRKDIR_BIN}/collector .)

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/collector ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/example-config.alloy ${STAGEDIR}${PREFIX}/etc/alloy.flow.sample
	${MKDIR} ${STAGEDIR}/var/${PORTNAME}

.include <bsd.port.mk>
