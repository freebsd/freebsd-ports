PORTNAME=	angie-module-upload
GH_TUPLE=	fdintino:nginx-upload-module:2.3.0:module

COMMENT=	Angie upload dynamic module

LICENSE_FILE=	${WRKSRC_module}/LICENCE

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_upload_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_upload_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_upload_module-debug.so

.include "${MASTERDIR}/Makefile"
