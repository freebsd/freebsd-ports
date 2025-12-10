PORTNAME=	angie-module-zstd
MODULE_VERSION=	0.1.1
MODULE_PORTREVISION=	0
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

.for i in ngx_http_zstd_static_module ngx_http_zstd_filter_module
	${INSTALL_LIB} ${WRKSRC}/objs/${i}.so ${STAGEDIR}${MODDIR}
.endfor

.for i in README.md
	${INSTALL_MAN} ${WRKSRC_module}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include "${MASTERDIR}/Makefile"
