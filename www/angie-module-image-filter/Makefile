PORTNAME=	angie-module-image-filter

COMMENT=	Angie image-filter dynamic module

LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd

CONFIGURE_ADD=	--with-http_image_filter_module=dynamic

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_image_filter_module.so \
	    ${STAGEDIR}${MODDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_image_filter_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_image_filter_module-debug.so

.include "${MASTERDIR}/Makefile"
