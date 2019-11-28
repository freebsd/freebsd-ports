# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	phpbb
DISTVERSION=	3.2.8
CATEGORIES=	www
MASTER_SITES=	https://download.phpbb.com/pub/release/${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}/${PORTVERSION}/
PKGNAMESUFFIX=	3
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PHP-based bulletin board / discussion forum system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USES=		php tar:bzip2
USE_PHP=	ctype hash json tokenizer

CONFLICTS=	phpbb-[0-2]*

OPTIONS_DEFINE=	DOCS

WWWDOCROOT?=	www
PHPBBURL?=	phpBB3

WRKSRC=		${WRKDIR}/phpBB3
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}"

PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
PORTDOCS=	*

options:
	@${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

do-install:
	${MV} ${WRKSRC}/config.php ${WRKSRC}/config.php.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PHPBBDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
