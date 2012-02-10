# New ports collection makefile for:	glpi
# Date created:			9 February 2007
# Whom:				Mathias Monnerville <mathias@monnerville.com>
#
# $FreeBSD$
#

PORTNAME=	glpi
DISTVERSION=	0.80.61
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://droidng.free.fr/freebsd/ \
		http://glpi-project.org/IMG/gz/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

USE_PHP=	mysql mbstring pcre session xml json
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

GLPIDIR?=	www/${PORTNAME}

OPTIONS=	LDAP "With LDAP support" off \
		IMAP "With imap support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '*~' -delete

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	  -e 's,%%GLPIDIR%%,${GLPIDIR},g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
