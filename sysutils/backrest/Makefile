PORTNAME=	backrest
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Web UI and orchestrator for restic backup
WWW=		https://garethgeorge.github.io/${PORTNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	restic>=0:sysutils/restic

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/garethgeorge/${PORTNAME}
GO_TARGET=	./cmd/backrest
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.version=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'main.commit=${GITID}' \
			-X 'main.date=${BUILD_DATE}'"

SUB_FILES=	${PORTNAME}.env pkg-message
SUB_LIST=	HOMEDIR=${BACKREST_HOMEDIR} \
		USER=${BACKREST_USER}

PLIST_FILES=	"@dir(${BACKREST_USER},${BACKREST_GROUP},0700) ${BACKREST_HOMEDIR}" \
		"@sample ${ETCDIR}/config.env.sample" \
		bin/${PORTNAME}

OPTIONS_DEFINE=		RCLONE
OPTIONS_DEFAULT=	RCLONE

RCLONE_DESC=		Cloud storage support
RCLONE_RUN_DEPENDS=	rclone>=0:net/rclone

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the Backrest repository to get the value of GITID.
GITID=		7a5030bb00f113170e1c09c45a4f2034a13a2809

BUILD_DATE=	$$(date -u '+%Y-%m-%dT%H:%M:%SZ')

BACKREST_HOMEDIR=	/var/db/${PORTNAME}
BACKREST_USER=		www
BACKREST_GROUP=		${BACKREST_USER}

pre-build:
	@${MKDIR} ${WRKSRC}/webui/dist
	@cd ${WRKDIR}/backrest-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/webui/dist

post-install:
	@${MKDIR} ${STAGEDIR}${BACKREST_HOMEDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.env ${STAGEDIR}${ETCDIR}/config.env.sample

.include <bsd.port.mk>
