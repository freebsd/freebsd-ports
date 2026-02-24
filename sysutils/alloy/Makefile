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

# nodefault required: go.mk sets WRKSRC to the Go module path (${GO_MODNAME}@version).
# Without nodefault, bsd.port.mk warns "USE_GITHUB and WRKSRC is set"; we cannot remove
# WRKSRC because go:modules requires it. GH_PROJECT is set correctly for the tarball.
USE_GITHUB=	yes,nodefault
GH_ACCOUNT=	grafana
GH_PROJECT=	alloy

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-install
# Use same script for deinstall so DEINSTALL case runs and stops the service on pkg remove.
PKGDEINSTALL=	${WRKDIR}/pkg-install

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
# Binary is built by custom do-build from collector/ (separate Go module with own go.mod).
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

# Fetch phase: download collector submodule deps into same module cache (extract has no network in poudriere).
_USES_fetch+=	900:alloy-fetch-collector-deps
alloy-fetch-collector-deps:
	@${ECHO_MSG} "===> Fetching collector submodule dependencies"; \
	td=$$(mktemp -d -t alloy_collector_deps); \
	trap "rm -rf $$td" 0; \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} -C $$td; \
	(cd $$td/${PORTNAME}-${DISTVERSION}/collector && \
		${SETENVI} ${WRK_ENV} GOPATH="${GO_GOPATH}" GO111MODULE=on GOFLAGS=-modcacherw GOSUMDB=sum.golang.org \
		GOPROXY=${GO_GOPROXY} ${GO_CMD} mod download -x all); \
	rm -rf $$td


# Copy main module vendor into tarball after go-post-extract (800). Then vendor collector from cache (populated at fetch).
_USES_extract+=	900:alloy-post-go-extract
alloy-post-go-extract:
	@if [ -d ${GO_WRKSRC}/vendor ]; then \
		${CP} -r ${GO_WRKSRC}/vendor ${WRKDIR}/${PORTNAME}-${DISTVERSION}/; \
	else \
		${ECHO_MSG} "===> WARNING: ${GO_WRKSRC}/vendor missing (go mod vendor may have failed)"; \
	fi
	@${ECHO_MSG} "===> Vendoring collector submodule"; \
	(cd ${WRKDIR}/${PORTNAME}-${DISTVERSION}/collector && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} \
		${GO_CMD} mod vendor -e)

# Define before .include so bsd.port.mk and go.mk see !target(do-build/do-install) and do not add defaults.
_GO_WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
# Collector is a Go submodule; vendor is populated in 900 hook so build can run offline (-mod=vendor).
do-build:
	(cd ${_GO_WRKSRC}/collector; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off \
		${GO_CMD} build ${GO_BUILDFLAGS} -mod=vendor -o ${GO_WRKDIR_BIN}/collector .)

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/collector ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/example-config.alloy ${STAGEDIR}${PREFIX}/etc/alloy.flow.sample
	${MKDIR} ${STAGEDIR}/var/${PORTNAME}

.include <bsd.port.mk>
