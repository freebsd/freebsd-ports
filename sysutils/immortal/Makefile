# $FreeBSD$

PORTNAME=	immortal
PORTVERSION=	0.16.0
CATEGORIES=	sysutils

MAINTAINER=	nbari@tequila.io
COMMENT=	Unix cross-platform (OS agnostic) supervisor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_RC_SUBR=	immortaldir
USE_GITHUB=	yes
GH_TUPLE=	immortal:logrotate:8591051:logrotate/src/github.com/immortal/logrotate \
		immortal:multiwriter:2555774:multiwriter/src/github.com/immortal/multiwriter \
		immortal:natcasesort:69368b7:natcasesort/src/github.com/immortal/natcasesort \
		immortal:xtime:fb1aca1:xtime/src/github.com/immortal/xtime \
		nbari:violetear:13cb9a6:nbari/src/github.com/nbari/violetear \
		go-yaml:yaml:eb3733d:yaml/src/github.com/go-yaml/yaml
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w -X main.version=${PORTVERSION}" -o immortal cmd/immortal/main.go;
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w -X main.version=${PORTVERSION}" -o immortalctl cmd/immortalctl/main.go;
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w -X main.version=${PORTVERSION}" -o immortaldir cmd/immortaldir/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/immortal/immortal/immortal ${STAGEDIR}${PREFIX}/bin/immortal
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/immortal/immortal/immortalctl ${STAGEDIR}${PREFIX}/bin/immortalctl
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/immortal/immortal/immortaldir ${STAGEDIR}${PREFIX}/bin/immortaldir
	${INSTALL_MAN} ${WRKSRC}/src/github.com/immortal/immortal/man/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/www.yml ${STAGEDIR}${ETCDIR}/www.yml.sample

.include <bsd.port.mk>
