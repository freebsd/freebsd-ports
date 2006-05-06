# Ports collection makefile for:	PmWiki
# Date created:		Sat Feb 26 06:16:50 CST 2005
# Whom:				Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pmwiki
PORTVERSION=	2.1.5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	A WikiWikiWeb clone using PHP

USE_PHP=	mbstring
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes

PLIST_SUB+=	PMWIKIDIR=${PMWIKIDIR}
SUB_LIST+=	PMWIKIDIR=${PMWIKIDIR}
SUB_FILES=	pkg-message

pre-fetch:
.if !defined(PMWIKIDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define PMWIKIDIR to override default of ${PMWIKIDIR}."
	@${ECHO_MSG} ""
.endif

PMWIKIDIR?=	www/data/pmwiki
WWWUSER?=	www
WWWGROUP?=	www

do-install:
	@${MKDIR} -m 755 ${PREFIX}/${PMWIKIDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PMWIKIDIR}
	@${CHOWN} ${WWWUSER}:${WWWGROUP} ${PREFIX}/${PMWIKIDIR}

post-install:
	@${MKDIR} -m 775 ${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CHOWN} ${WWWUSER}:${WWWGROUP} ${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
