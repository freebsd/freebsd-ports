# New ports collection makefile for:	ipv6calc
# Date created:				30 January 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	ipv6calc
PORTVERSION=	0.46
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Convert, change and calculate with IPv6 addresses

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ipv6calc/ipv6calc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/ipv6logconv/ipv6logconv ${PREFIX}/bin

.include <bsd.port.mk>
