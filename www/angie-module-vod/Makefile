PORTNAME=	angie-module-vod
MODULE_VERSION=	1.33
MODULE_PORTREVISION=	0
GH_TUPLE=	kaltura:nginx-vod-module:${MODULE_VERSION}:module

COMMENT=	VOD dynamic module for Angie
WWW=		https://github.com/kaltura/nginx-vod-module/

LICENSE= AGPLv3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_vod_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_vod_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_vod_module-debug.so

.include "${MASTERDIR}/Makefile"
