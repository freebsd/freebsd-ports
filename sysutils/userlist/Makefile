# New ports collection makefile for:	userlist
# Date created:			8 May 2001
# Whom:				Jamie Heckford <jamie@jamiesdomain.co.uk>
#
# $FreeBSD$
#

PORTNAME=	userlist
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.jamiesdomain.org.uk/userlist/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints a list of all usernames in /etc/passwd

NO_BUILD=	yes
PLIST_FILES=	bin/userlist
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/userlist ${PREFIX}/bin

.include <bsd.port.mk>
