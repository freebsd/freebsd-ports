PORTNAME=	angie-module-zstd
MODULE_VERSION=	0.1.1
MODULE_PORTREVISION=	3
GH_TUPLE=	tokers:zstd-nginx-module:${MODULE_VERSION}:module

COMMENT=	Angie zstd dynamic module
WWW=		https://github.com/tokers/zstd-nginx-module/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_module}

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB}  ${WRKSRC}/objs/ngx_http_zstd_static_module.so \
			${WRKSRC}/objs/ngx_http_zstd_filter_module.so \
		${STAGEDIR}${MODDIR}

	${INSTALL_DATA} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

.include "${MASTERDIR}/Makefile"
