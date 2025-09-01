PORTNAME=	sqlpage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.1
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	https://cdn.jsdelivr.net/npm/:npm
DISTFILES=	${NPM_DISTFILES}
EXTRACT_ONLY=	${_DISTFILES:M*${EXTRACT_SUFX}} ${_DISTFILES:M*crate}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	SQL-only webapp builder.
WWW=		https://github.com/lovasoa/SQLPage

LICENSE=	MIT

LIB_DEPENDS=	libzstd.so:archivers/zstd

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		LLVM_CONFIG_PATH=${LLVM_CONFIG}

USES=		cargo llvm
USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	lovasoa
GH_PROJECT=	SQLPage

USERS=		sqlpage
GROUPS=		sqlpage

NPM_DISTFILES=	apexcharts@5.3.0/dist/apexcharts.min.js:npm \
		@tabler/core@1.4.0/dist/css/tabler.min.css:npm \
		@tabler/core@1.4.0/dist/css/tabler-vendors.min.css:npm \
		@tabler/core@1.4.0/dist/js/tabler.min.js:npm \
		@tabler/icons-sprite@3.34.0/dist/tabler-sprite.svg:npm \
		tom-select@2.4.3/dist/css/tom-select.bootstrap5.css:npm \
		tom-select@2.4.1/dist/js/tom-select.popular.min.js:npm

ARTEFACTS=	${WRKSRC}/target/sqlpage_artefacts

post-extract:
		${MKDIR} ${ARTEFACTS}
.for f in ${NPM_DISTFILES:S/:npm//}
		${CP} ${DISTDIR}/$f ${ARTEFACTS}/https___cdn.jsdelivr.net_npm_${f:C/[\@\/]/_/g}
.endfor

post-install:
		${MKDIR} ${STAGEDIR}/${ETCDIR} ;\
		 ${INSTALL_DATA} ${FILESDIR}/sqlpage.json ${STAGEDIR}${ETCDIR}/sqlpage.json.sample
		${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}${DATADIR} ;\
		 ${INSTALL_DATA} ${WRKSRC}/src/index.sql ${STAGEDIR}${DATADIR}
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d ;\
		 ${INSTALL_DATA} ${FILESDIR}/sqlpage.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/sqlpage.conf.sample

.include <bsd.port.mk>
