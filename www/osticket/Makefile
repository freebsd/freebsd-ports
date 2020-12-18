# Created by: Juraj Lutter <otis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osticket
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/osTicket/osTicket/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	osTicket-v${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Widely-used open source support ticket system

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}

USES=		php:web zip
USE_PHP=	gd gettext imap json mbstring mysqli xml
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

WRKSRC=		${WRKDIR}/upload

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=	DOCS

_OSTDOCS=	ISSUE_TEMPLATE.md LICENSE.txt README.md SECURITY.md \
		UPGRADING.txt WHATSNEW.md

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/
	${MV} ${STAGEDIR}${WWWDIR}/include/ost-sampleconfig.php \
	  ${STAGEDIR}${WWWDIR}/include/ost-config.php.sample

post-install:
	${RM} ${_OSTDOCS:S,^,${STAGEDIR}${WWWDIR}/,}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_OSTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
