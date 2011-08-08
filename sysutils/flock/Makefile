# New ports collection makefile for:	flock
# Date created:				26 May 2011
# Whom:					Andrey Zonov <andrey@zonov.org>
#
# $FreeBSD$
#

PORTNAME=	flock
PORTVERSION=	2.19
CATEGORIES=	sysutils
MASTER_SITES=	http://www.zonov.org/${PORTNAME}/

MAINTAINER=	andrey@zonov.org
COMMENT=	Manage locks from shell scripts

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
