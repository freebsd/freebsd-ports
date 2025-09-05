PORTNAME=	syncthing
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.7
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

# Anonymize
MAKE_ENV+=	BUILD_HOST=freebsd \
		BUILD_USER=ports

CONFLICTS_INSTALL=	syncthing1

NO_CCACHE=	yes
NO_WRKSUBDIR=	yes

USERS=		syncthing
GROUPS=		syncthing

.for x in ${BINS}
PLIST_FILES+=	bin/${x}
.endfor

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	@( cd ${WRKSRC}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build stdiscosrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build strelaysrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade build strelaypoolsrv; \
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

do-test:
	@( cd ${WRKSRC}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${DISTVERSION} -no-upgrade test ; \
		)
.include <bsd.port.mk>
