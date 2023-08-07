PORTNAME=	angie-module-xslt

COMMENT=	Angie XSLT dynamic module

LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxslt.so:textproc/libxslt

CONFIGURE_ADD=	--with-http_xslt_module=dynamic

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_xslt_filter_module.so \
	    ${STAGEDIR}${MODDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_xslt_filter_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_xslt_filter_module-debug.so

.include "${MASTERDIR}/Makefile"
