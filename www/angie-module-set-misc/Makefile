PORTNAME=	angie-module-set-misc
GH_TUPLE=	vision5:ngx_devel_kit:v0.3.4:ndk
GH_TUPLE+=	openresty:set-misc-nginx-module:v0.33:module

COMMENT=	Angie set-misc dynamic module

LICENSE_FILE=	${WRKSRC_module}/README.markdown

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_ndk} \
		--add-dynamic-module=${WRKSRC_module}

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_set_misc_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_set_misc_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_set_misc_module-debug.so

.include "${MASTERDIR}/Makefile"
