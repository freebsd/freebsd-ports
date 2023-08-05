PORTNAME=	angie-module-geoip2
GH_TUPLE=	leev:ngx_http_geoip2_module:3.4:module

COMMENT=	Angie GeoIP2 dynamic module

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

.for i in ngx_http_geoip2_module ngx_stream_geoip2_module
	${INSTALL_LIB} ${WRKSRC}/objs/${i}.so ${STAGEDIR}${MODDIR}
.endfor

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
.for i in ngx_http_geoip2_module ngx_stream_geoip2_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
