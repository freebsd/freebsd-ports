# ex:ts=8
# New ports collection makefile for:	romeo
# Date created:			Mar 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	romeo
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Palm ROM Discombobulator

BROKEN=		Does not compile with GCC 4.2
DEPRECATED=	does not compile on FreeBSD 7.x or newer
EXPIRATION_DATE=2011-04-17

PLIST_FILES=	bin/romeo
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/romeo ${PREFIX}/bin

.include <bsd.port.mk>
