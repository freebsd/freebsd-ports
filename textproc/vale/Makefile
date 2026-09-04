PORTNAME=	vale
DISTVERSIONPREFIX=	v
DISTVERSION=	3.20.0
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line tool that brings editorial style guide to life
WWW=		https://vale.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/errata-ai/${PORTNAME}/v3
GO_TARGET=	./cmd/vale

PLIST_FILES=	bin/vale

do-build:
	(cd ${GO_WRKSRC}; \
	for t in ${GO_TARGET}; do \
		out=$$(${BASENAME} $$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^[^:]*:([^:]+).*$$/\1/' -e 's/^\.$$/${PORTNAME}/')); \
		pkg=$$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^([^:]*).*$$/\1/' -e 's/^${PORTNAME}$$/./'); \
		${ECHO_MSG} "===>  Building $${out} from $${pkg}"; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} build \
			-ldflags="-s -w -X main.Version=${DISTVERSION}" -mod=mod -buildmode=exe -v -trimpath -buildvcs=false \
			-o ${GO_WRKDIR_BIN}/$${out} \
			$${pkg}; \
	done)

.include <bsd.port.mk>
