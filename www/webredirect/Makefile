# New ports collection makefile for:	webredirect
# Date created:		24 October 2000
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	webredirect
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	ftp://Raditex.se/pub/kaj/

MAINTAINER=	rasmus@kaj.se

ALL_TARGET=	depend all

MAN1=		webredirect.1

pre-build:
	@${TOUCH} ${WRKSRC}/incu/depend.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webredirect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webredirect.1 ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
