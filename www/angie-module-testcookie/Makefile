PORTNAME=	angie-module-testcookie
GH_TUPLE=	kyprizel:testcookie-nginx-module:64137c2f7e66e8866f56fdecaaf09ac10a034da9:module

COMMENT=	Angie testcookie dynamic module
WWW=		https://github.com/kyprizel/testcookie-nginx-module/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC_module}/README.markdown

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_testcookie_access_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/Changelog ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_testcookie_access_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_testcookie_access_module-debug.so

.include "${MASTERDIR}/Makefile"
