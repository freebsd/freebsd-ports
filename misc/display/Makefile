# New ports collection makefile for: display
# Date created:		25 August 1997
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=		display
PORTVERSION=		1.1
CATEGORIES=		misc
MASTER_SITES=		http://www.ipsmart.com/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ports@FreeBSD.org

GNU_CONFIGURE=		yes

MAN1=			display.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/display ${PREFIX}/bin/display
	@${INSTALL_MAN} ${WRKSRC}/display.man ${PREFIX}/man/man1/display.1

.include <bsd.port.mk>
