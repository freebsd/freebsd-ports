PORTNAME=	angie-module-njs
GH_TUPLE=	nginx:njs:0.9.1:module

COMMENT=	Angie NJS dynamic module

LIB_DEPENDS=	libxslt.so:textproc/libxslt

USES=		gnome
USE_GNOME=	libxml2

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_module}/nginx

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

.for i in ngx_http_js_module ngx_stream_js_module
	${INSTALL_LIB} ${WRKSRC}/objs/${i}.so ${STAGEDIR}${MODDIR}
.endfor

.for i in CHANGES README.md SECURITY.md SUPPORT.md
	${INSTALL_MAN} ${WRKSRC_module}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-DEBUG-on:
.for i in ngx_http_js_module ngx_stream_js_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
