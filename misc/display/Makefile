# New ports collection makefile for: display
# Date created:		25 August 1997
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	display
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.ipsmart.com/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Runs command repeatedly; shows output

CONFLICTS=	ImageMagick-[0-9]* goblin-*

GNU_CONFIGURE=	yes

MAN1=		display.1
PLIST_FILES=	bin/display

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/display ${PREFIX}/bin/display
	${INSTALL_MAN} ${WRKSRC}/display.man ${MANPREFIX}/man/man1/display.1

.include <bsd.port.mk>
