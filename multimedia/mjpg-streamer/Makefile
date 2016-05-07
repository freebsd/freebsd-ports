# Created by: Kozlov Sergey <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	mjpg-streamer
PORTVERSION=	r63
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sourcecode

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	HTTP video streaming daemon

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat

APP_BINARY=	mjpg_streamer
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DEBUG_FLAGS+=	-DDEBUG
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DEBUG
OPTIONS_MULTI=	INPUT_PLUGINS OUTPUT_PLUGINS
OPTIONS_MULTI_INPUT_PLUGINS=	TESTPICTURE UVC
OPTIONS_MULTI_OUTPUT_PLUGINS=	HTTP FILE

TESTPICTURE_DESC=	Test picture plugin
UVC_DESC=	Linux-UVC V4L2 plugin

HTTP_DESC=	HTTP streaming plugin
FILE_DESC=	File output plugin

OPTIONS_DEFAULT=	TESTPICTURE UVC HTTP FILE
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTPICTURE}
MJPEG_STREAMER_PLUGINS+=	input_testpicture.so
.endif

.if ${PORT_OPTIONS:MUVC}
MJPEG_STREAMER_PLUGINS+=	input_uvc.so
USES+=		jpeg
.endif

.if ${PORT_OPTIONS:MHTTP}
MJPEG_STREAMER_PLUGINS+=	output_http.so
.endif

.if ${PORT_OPTIONS:MFILE}
MJPEG_STREAMER_PLUGINS+=	output_file.so
.endif

.if ${PORT_OPTIONS:MHTTP}
.if ${PORT_OPTIONS:MUVC}
USE_RC_SUBR=	mjpg_streamer
SUB_FILES+=	pkg-message
.endif
.endif

ALL_TARGET=	${APP_BINARY} ${MJPEG_STREAMER_PLUGINS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${APP_BINARY} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	@for plugin in ${MJPEG_STREAMER_PLUGINS}; do \
		${INSTALL_LIB} ${WRKSRC}/$${plugin} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}; \
	done
.if ${PORT_OPTIONS:MHTTP}
	cd ${WRKSRC}/www && \
	${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR}
.endif

.include <bsd.port.mk>
