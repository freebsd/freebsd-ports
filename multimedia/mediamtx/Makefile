PORTNAME=	mediamtx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES+=	https://github.com/video-dev/hls.js/releases/download/v1.6.10/
DISTFILES+=	release.zip

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Ready-to-use RTSP / RTMP / LL-HLS / WebRTC server and proxy that allows to read, publish and proxy video and audio streams
WWW=		https://github.com/bluenviron/mediamtx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/bluenviron/mediamtx

USE_RC_SUBR=	mediamtx

USERS=		mediamtx
GROUPS=		mediamtx

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}

post-extract:
	${MV} ${WRKDIR}/dist/hls.min.js ${WRKSRC}/internal/servers/hls
	${RM} -r ${WRKSRC}/internal/staticsources/rpicamera

pre-configure:
	${ECHO} ${DISTVERSIONFULL} > ${WRKSRC}/internal/core/VERSION

post-install:
	${INSTALL_DATA} ${WRKSRC}/mediamtx.yml ${STAGEDIR}${PREFIX}/etc/mediamtx.yml.sample
	
.include <bsd.port.mk>
