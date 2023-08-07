PORTNAME=	angie-module-brotli
GH_TUPLE=	google:ngx_brotli:v1.0.0rc:module

COMMENT=	Angie Brotli dynamic module

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

.for i in ngx_http_brotli_filter_module ngx_http_brotli_static_module
	${INSTALL_LIB} ${WRKSRC}/objs/${i}.so ${STAGEDIR}${MODDIR}
.endfor

.for i in CONTRIBUTING README
	${INSTALL_MAN} ${WRKSRC_module}/${i}.md ${STAGEDIR}${DOCSDIR}
.endfor

do-install-DEBUG-on:
.for i in ngx_http_brotli_filter_module ngx_http_brotli_static_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
