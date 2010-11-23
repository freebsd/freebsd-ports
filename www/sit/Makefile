# New ports collection makefile for:	sit
# Date created:				Wed Oct 7, 2010
# Whom:					Carsten Jensen <carsten@sitracker.org>
#
# $FreeBSD$
#

PORTNAME=	sit
PORTVERSION=	3.62
CATEGORIES=	www
MASTER_SITES=	SF/sitracker/stable/${PORTVERSION}/
DISTNAME=	sit_${PORTVERSION}

MAINTAINER=	carsten@sitracker.org
COMMENT=	A PHP incident tracking system / Helpdesk

LICENSE=	GPLv2

USE_PHP=	pcre mysql session zlib mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/sit-${PORTVERSION}

SUB_FILES=	pkg-message

OPTIONS=	IMAP		"If you want email to work"			on \
		MBSTRING	"If you want to use the inbound email feature"	on \
		LDAP		"If you want to use LDAP auth"			off

.include <bsd.port.pre.mk>

.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} -R ${BINMODE} ${WWWDIR}
	${FIND} ${WWWDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

	@${CAT} ${PKGMESSAGE}

post-install:
	@if [ -f ${WWWDIR}/config.inc.php ]; then \
		${CP} -p ${WWWDIR}/config.inc.php ${WWWDIR}/config.inc.php.bak ; \
	fi

.include <bsd.port.post.mk>
