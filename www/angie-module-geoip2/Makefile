PORTNAME=	angie-module-geoip2
MODULE_VERSION=	3.4
MODULE_PORTREVISION=	3
GH_TUPLE=	leev:ngx_http_geoip2_module:${MODULE_VERSION}:module

COMMENT=	Angie GeoIP2 dynamic module
WWW=		https://github.com/leev/ngx_http_geoip2_module/

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB}  ${WRKSRC}/objs/ngx_http_geoip2_module.so \
			${WRKSRC}/objs/ngx_stream_geoip2_module.so \
		${STAGEDIR}${MODDIR}

	${INSTALL_DATA} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
.for i in ngx_http_geoip2_module ngx_stream_geoip2_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
