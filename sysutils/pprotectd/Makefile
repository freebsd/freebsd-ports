# New ports collection makefile for:	pprotectd
# Date created:				15 July 2010
# Whom:					Andrey Zonov <andrey@zonov.org>
#
# $FreeBSD$
#

PORTNAME=	pprotectd
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.zonov.org/${PORTNAME}/

MAINTAINER=	andrey@zonov.org
COMMENT=	A daemon that protects processes from killing when memory is exhausted

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME}
MAN8=		${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

.include <bsd.port.mk>
