PORTNAME=	angie-module-njs
MODULE_VERSION=	0.9.5
MODULE_PORTREVISION=	2
GH_TUPLE=	nginx:njs:${MODULE_VERSION}:module

COMMENT=	Angie NJS dynamic module
WWW=		https://github.com/nginx/njs/

LIB_DEPENDS=	libxslt.so:textproc/libxslt

USES=		gnome
USE_GNOME=	libxml2

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_module}/nginx

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB}  ${WRKSRC}/objs/ngx_http_js_module.so \
			${WRKSRC}/objs/ngx_stream_js_module.so \
		${STAGEDIR}${MODDIR}

	${INSTALL_DATA} ${CHANGES README.md SECURITY.md SUPPORT.md:L:S|^|${WRKSRC_module}/|} \
		${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
.for i in ngx_http_js_module ngx_stream_js_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
