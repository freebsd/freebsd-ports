PORTNAME=	angie-module-ndk
GH_TUPLE=	vision5:ngx_devel_kit:v0.3.4:module

COMMENT=	Angie NDK dynamic module

CFLAGS+=	-DNDK_SET_VAR -DNDK_UPSTREAM_LIST

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ndk_http_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ndk_http_module.so \
	    ${STAGEDIR}${MODDIR}/ndk_http_module-debug.so

.include "${MASTERDIR}/Makefile"
