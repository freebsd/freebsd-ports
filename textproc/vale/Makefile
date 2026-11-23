PORTNAME=	vale
DISTVERSIONPREFIX=	v
DISTVERSION=	3.28.0
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line tool that brings editorial style guide to life
WWW=		https://vale.sh/

LICENSE=	Apache-2.0 BSD-2-Clause BSD-3-Clause LicenseRef-SCOWL-Atkinson MIT
LICENSE_COMB=	multi
LICENSE_NAME_LicenseRef-SCOWL-Atkinson=	SCOWL (Spell Checker Oriented Word Lists) License
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_Apache-2.0=	${WRKSRC}/vendor/github.com/tetratelabs/wazero/LICENSE
LICENSE_FILE_BSD-2-Clause=	${WRKSRC}/vendor/github.com/andybalholm/cascadia/LICENSE
LICENSE_FILE_BSD-3-Clause=	${WRKSRC}/vendor/golang.org/x/text/LICENSE
LICENSE_FILE_LicenseRef-SCOWL-Atkinson=	${FILESDIR}/LICENSE.SCOWL
LICENSE_PERMS_LicenseRef-SCOWL-Atkinson=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

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
