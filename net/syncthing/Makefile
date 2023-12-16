PORTNAME=	syncthing
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSIONFULL}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Encrypted file sync tool
WWW=		https://syncthing.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE

USES=		cpe go:modules

USE_RC_SUBR=	syncthing syncthing-discosrv syncthing-relaysrv \
		syncthing-relaypoolsrv

BINS=		syncthing stdiscosrv strelaysrv strelaypoolsrv

.for x in ${BINS}
PLIST_FILES+=	bin/${x}
.endfor

PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

# Anonymize
MAKE_ENV+=	BUILD_HOST=freebsd \
		BUILD_USER=ports

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

do-build:
	@( cd ${WRKSRC}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build stdiscosrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build strelaysrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build strelaypoolsrv; \
		)

do-test:
	@( cd ${WRKSRC}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade test ; \
		)

do-install:
.for x in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${x} \
		${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in AUTHORS LICENSE README.md
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
