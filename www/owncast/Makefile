PORTNAME=	owncast
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	www
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	de-freebsd@ctseuro.com
COMMENT=	Self-hosted streaming service written in Go
WWW=		https://owncast.online

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cpe go:1.23,modules
USE_RC_SUBR=	owncast

CPE_VENDOR=	owncast_project

GO_MODULE=	github.com/owncast/owncast

_DAEMONARGS=	-S -l \$${owncast_facility} -s \$${owncast_priority} -T \$${name}
_OWNCAST_USER=	owncast
_OWNCAST_GROUP=	owncast

SUB_LIST+=	DAEMONARGS="${_DAEMONARGS}" \
		OWNCAST_USER=${_OWNCAST_USER}

USERS=		${_OWNCAST_USER}
GROUPS=		${_OWNCAST_GROUP}

PLIST_SUB=	OWNCAST_USER=${_OWNCAST_USER} \
		OWNCAST_GROUP=${_OWNCAST_GROUP}

post-patch:
	@${ECHO_CMD} ${DISTVERSION} >${WRKSRC}/VERSION

do-install:
	# Go binary is statically linked and cannot be stripped, so use
	# INSTALL_SCRIPT.
	${INSTALL_SCRIPT} ${WRKDIR}/bin/owncast ${STAGEDIR}${PREFIX}/sbin

	${MKDIR} -m 750 ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "static" ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${WWWDIR}
	${MKDIR} -m 750 ${STAGEDIR}${WWWDIR}/backup
	${MKDIR} -m 750 ${STAGEDIR}${WWWDIR}/data
	${MKDIR} -m 750 ${STAGEDIR}${WWWDIR}/hls
	${MKDIR} -m 750 ${STAGEDIR}${WWWDIR}/webroot/hls

.include <bsd.port.mk>
