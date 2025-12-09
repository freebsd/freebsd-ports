PORTNAME=	angie-module-postgres
MODULE_VERSION=	1.0rc7
MODULE_PORTREVISION=	0
GH_TUPLE=	FRiCKLE:ngx_postgres:${MODULE_VERSION}:module

COMMENT=	Angie postgres dynamic module
WWW=		https://github.com/FRiCKLE/ngx_postgres/

USES=		pgsql

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_postgres_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_postgres_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_postgres_module-debug.so

.include "${MASTERDIR}/Makefile"
