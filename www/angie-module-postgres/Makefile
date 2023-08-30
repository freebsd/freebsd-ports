PORTNAME=	angie-module-postgres
GH_TUPLE=	FRiCKLE:ngx_postgres:1.0rc7:module

COMMENT=	Angie postgres dynamic module

USES=		pgsql

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_postgres_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_postgres_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_postgres_module-debug.so

.include "${MASTERDIR}/Makefile"
