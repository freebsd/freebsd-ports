PORTNAME=	angie-module-brotli
MODULE_VERSION=	1.0.0rc
MODULE_PORTREVISION=	3
GH_TUPLE=	google:ngx_brotli:v${MODULE_VERSION}:module

COMMENT=	Angie Brotli dynamic module
WWW=		https://github.com/google/ngx_brotli/

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB}  ${WRKSRC}/objs/ngx_http_brotli_filter_module.so \
			${WRKSRC}/objs/ngx_http_brotli_static_module.so \
		${STAGEDIR}${MODDIR}

	${INSTALL_DATA} ${WRKSRC_module}/CONTRIBUTING.md \
			${WRKSRC_module}/README.md \
		${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
.for i in ngx_http_brotli_filter_module ngx_http_brotli_static_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
