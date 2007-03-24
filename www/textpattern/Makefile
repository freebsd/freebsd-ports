# New ports collection makefile for:	textpattern
# Date created:		30 Nov 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	textpattern
PORTVERSION=	4.0.4
CATEGORIES=	www
MASTER_SITES=	http://www.farrokhi.net/distfiles/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A free, flexible, elegant, easy-to-use content management system

NO_BUILD=	YES
WANT_PHP_WEB=	YES
TEXTPATTERN?=	www/${PORTNAME}
PLIST_SUB+=	TEXTPATTERN=${TEXTPATTERN}
USE_PHP=	mbstring xml mysql

do-install:
	-${MKDIR} ${PREFIX}/${TEXTPATTERN}
	@(cd ${WRKSRC} && ${CP} -R * ${PREFIX}/${TEXTPATTERN}/ )

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
