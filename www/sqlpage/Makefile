# FATAL: Makefile: order must be PORTNAME/PORTVERSION/DISTVERSIONPREFIX/DISTVERSION/DISTVERSIONSUFFIX/PORTREVISION/PORTEPOCH/CATEGORIES/MASTER_SITES/MASTER_SITE_SUBDIR/PROJECTHOST/PKGNAMEPREFIX/PKGNAMESUFFIX/DISTNAME/EXTRACT_SUFX/DISTFILES(_\w+)?/DIST_SUBDIR/EXTRACT_ONLY.

PORTNAME=	sqlpage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	www databases
MASTER_SITES=	https://cdn.jsdelivr.net/npm/:npm
DISTFILES=	${NPM_DISTFILES}
EXTRACT_ONLY=	${_DISTFILES:M*${EXTRACT_SUFX}} ${_DISTFILES:M*crate}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	SQL-only webapp builder.
WWW=		https://github.com/lovasoa/SQLpage

LICENSE=	MIT

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	lovasoa
GH_PROJECT=	SQLpage

USERS=		sqlpage
GROUPS=		sqlpage

NPM_DISTFILES=	apexcharts@3.47.0/dist/apexcharts.min.js:npm \
		@tabler/core@1.0.0-beta20/dist/css/tabler.min.css:npm \
		@tabler/core@1.0.0-beta20/dist/css/tabler-vendors.min.css:npm \
		@tabler/core@1.0.0-beta20/dist/js/tabler.min.js:npm \
		list.js-fixed@2.3.4/dist/list.min.js:npm \
		@tabler/icons@2.47.0/tabler-sprite.svg:npm

post-extract:
		cd ${DISTDIR}; ${PAX} -rw ${NPM_DISTFILES:C/\/.*//g} ${WRKSRC}

post-install:
		${MKDIR} ${STAGEDIR}/${ETCDIR} ;\
		 ${INSTALL_DATA} ${FILESDIR}/sqlpage.json ${STAGEDIR}${ETCDIR}/sqlpage.json.sample
		${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}${DATADIR} ;\
		 ${INSTALL_DATA} ${WRKSRC}/index.sql ${STAGEDIR}${DATADIR}
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d ;\
		 ${INSTALL_DATA} ${FILESDIR}/sqlpage.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/sqlpage.conf.sample
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
