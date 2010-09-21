# New ports collection makefile for: display
# Date created:		25 August 1997
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	display
PORTVERSION=	1.2a
CATEGORIES=	misc
MASTER_SITES=	http://www.ipsmart.com/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjroz@verizon.net
COMMENT=	Runs command repeatedly; shows output

GNU_CONFIGURE=	yes

DISPLAY_PROGRAM_PREFIX?=

.if empty(DISPLAY_PROGRAM_PREFIX)
pre-everything::
		@${ECHO_MSG} "NOTE: You may set DISPLAY_PROGRAM_PREFIX to change the name of the 'display'"
		@${ECHO_MSG} "utility so that it does not conflict with similarly named files from"
		@${ECHO_MSG} "the ImageMagick and goblin ports."

CONFLICTS=	ImageMagick-[0-9]* goblin-*
.endif

CONFIGURE_ARGS+=	--program-prefix=${DISPLAY_PROGRAM_PREFIX}
CONFIGURE_ENV+=	LDFLAGS="${STRIP}"

MAN1=		${DISPLAY_PROGRAM_PREFIX}display.1
PLIST_FILES=	bin/${DISPLAY_PROGRAM_PREFIX}display

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/display ${PREFIX}/bin/${DISPLAY_PROGRAM_PREFIX}display
	${INSTALL_MAN} ${WRKSRC}/display.man ${MANPREFIX}/man/man1/${DISPLAY_PROGRAM_PREFIX}display.1

.include <bsd.port.mk>
