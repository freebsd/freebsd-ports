# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	phpbb
PORTVERSION=	3.1.9
CATEGORIES=	www
MASTER_SITES=	https://www.phpbb.com/files/release/
PKGNAMESUFFIX=	3
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	jochen@jochen-neumeister.de
COMMENT=	PHP-based bulletin board / discussion forum system

LICENSE=	GPLv2

CONFLICTS=	phpbb-tw-[0-9]* phpbb-devel-[0-9]* \
		phpbb-[0-2]*

USES=		php tar:bzip2

OPTIONS_DEFINE=	DOCS

WWWDOCROOT?=	www
PHPBBURL?=	phpBB3

WRKSRC=		${WRKDIR}/phpBB3
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}"

PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
PORTDOCS=	*

.include <bsd.port.options.mk>

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
.	if ${PORT_OPTIONS:MDOCS}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.	endif
	${MV} ${WRKSRC}/config.php ${WRKSRC}/config.php.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PHPBBDIR}

.include <bsd.port.mk>
