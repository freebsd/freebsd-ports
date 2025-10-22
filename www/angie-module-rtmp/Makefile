PORTNAME=	angie-module-rtmp
GH_TUPLE=	arut:nginx-rtmp-module:v1.2.2:module

COMMENT=	Angie RTMP dynamic module

DEPRECATED=	Upstream development has slowed down and there are a lot of unresolved issues and PRs upstream, consider migrating to multimedia/mediamtx
EXPIRATION_DATE=2025-12-31

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_rtmp_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_rtmp_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_rtmp_module-debug.so

.include "${MASTERDIR}/Makefile"
