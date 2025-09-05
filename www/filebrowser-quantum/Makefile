PORTNAME=	filebrowser-quantum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4-beta
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX} \
		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Web File Browser
WWW=		https://github.com/gtsteffaniak/filebrowser

LICENSE=	APACHE20

USES=		go:1.25,modules
USE_GITHUB=	yes
GH_ACCOUNT=	gtsteffaniak
GH_PROJECT=	filebrowser

USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./main.go:${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'github.com/gtsteffaniak/filebrowser/backend/common/version.Version=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'github.com/gtsteffaniak/filebrowser/backend/common/version.CommitSHA=${GITID}'"

SUB_FILES=	${PORTNAME}.yaml
SUB_LIST=	USER=${FILEBROWSER_QUANTUM_USER}

WRKSRC_SUBDIR=	backend

PLIST_SUB=	GROUP=${FILEBROWSER_QUANTUM_USER} \
		USER=${FILEBROWSER_QUANTUM_GROUP}

OPTIONS_DEFINE=		FFMPEG
OPTIONS_DEFAULT=	FFMPEG

FFMPEG_DESC=	Enable video thumbnail generation support

FFMPEG_RUN_DEPENDS=	ffmpeg>=0:multimedia/ffmpeg

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the FileBrowser Quantum repository to get the value of GITID.
GITID=		605ac44

FILEBROWSER_QUANTUM_USER=	www
FILEBROWSER_QUANTUM_GROUP=	${FILEBROWSER_QUANTUM_USER}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/filebrowser-quantum-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor
	@${MKDIR} ${WRKSRC}/http/embed
	@cd ${WRKDIR}/filebrowser-quantum-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/http/embed

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yaml.sample

.include <bsd.port.mk>
