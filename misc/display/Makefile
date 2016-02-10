# Created by: Stephen J. Roznowski <sjr@home.net>
# $FreeBSD$

PORTNAME=	display
PORTVERSION=	1.2a
CATEGORIES=	misc
MASTER_SITES=	http://www.ipsmart.com/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjroz@verizon.net
COMMENT=	Runs command repeatedly; shows output

USES=		ncurses
GNU_CONFIGURE=	yes

DISPLAY_PROGRAM_PREFIX?=

.if empty(DISPLAY_PROGRAM_PREFIX)
pre-everything::
		@${ECHO_MSG} "NOTE: You may set DISPLAY_PROGRAM_PREFIX to change the name of the 'display'"
		@${ECHO_MSG} "utility so that it does not conflict with similarly named files from"
		@${ECHO_MSG} "the ImageMagick and goblin ports."

CONFLICTS=	ImageMagick-[0-9]* goblin-*
.endif

PLIST_FILES=	bin/${DISPLAY_PROGRAM_PREFIX}display man/man1/${DISPLAY_PROGRAM_PREFIX}display.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/display ${STAGEDIR}${PREFIX}/bin/${DISPLAY_PROGRAM_PREFIX}display
	${INSTALL_MAN} ${WRKSRC}/display.man ${STAGEDIR}${MANPREFIX}/man/man1/${DISPLAY_PROGRAM_PREFIX}display.1

.include <bsd.port.mk>
