# Ports collection makefile for:	PmWiki
# Date created:		Sat Feb 26 06:16:50 CST 2005
# Whom:				Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pmwiki
PORTVERSION=	2.0b25
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/\.beta/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	A WikiWikiWeb clone using PHP

USE_PHP=	mbstring
PHP4_PORT?=	www/mod_php4
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB+=	PMWIKIDIR=${PMWIKIDIR}
PLIST=	${WRKDIR}/pkg-plist

pre-fetch:
.if !defined(PMWIKIDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define PMWIKIDIR to override default of 'www/data/pmwiki'."
	@${ECHO_MSG} ""
.endif

PMWIKIDIR?=	www/data/pmwiki
WWWUSER?=	www
WWWGROUP?=	www

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%PMWIKIDIR%%#${PMWIKIDIR}#g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 755 ${PREFIX}/${PMWIKIDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PMWIKIDIR}
	@${CHOWN} ${WWWUSER}:${WWWGROUP} ${PREFIX}/${PMWIKIDIR}

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | ${SED} -e 's|^|${PMWIKIDIR}/|' > ${PLIST} \
	&& ${FIND} -d * -type d | ${SED} -e 's|^|@dirrm ${PMWIKIDIR}/|' >> ${PLIST} \
	&& ${ECHO_MSG} "@unexec rmdir ${PMWIKIDIR} 2>/dev/null || true" >> ${PLIST}

post-install:
	@${MKDIR} -m 775 ${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CHOWN} ${WWWUSER}:${WWWGROUP} ${PREFIX}/${PMWIKIDIR}/wiki.d
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
