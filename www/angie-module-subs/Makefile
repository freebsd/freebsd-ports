PORTNAME=	angie-module-subs
GH_TUPLE=	yaoweibin:ngx_http_substitutions_filter_module:e12e965ac1837ca709709f9a26f572a54d83430e:module

COMMENT=	Angie substitutions filter dynamic module
WWW=		https://github.com/yaoweibin/ngx_http_substitutions_filter_module/

LICENSE_FILE=	${WRKSRC_module}/README

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_subs_filter_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_subs_filter_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_subs_filter_module-debug.so

.include "${MASTERDIR}/Makefile"
