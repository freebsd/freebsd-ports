# Ports collection makefile for:	xwlans
# Date created:				30 July 2004
# Whom:					Fredrik Lindberg <fredde@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	xwlans
PORTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://shapeshifter.se/code/xwlans/release/ \
		http://mirror.shapeshifter.se/code/xwlans/release/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	Utilty to display your wavelan signal strength on the X11 root-display

BROKEN=		Does not compile with GCC 4.2
DEPRECATED=	does not compile on FreeBSD 7.x or newer
EXPIRATION_DATE=2011-04-17

PLIST_FILES=	bin/xwlans
USE_XORG=	x11

.include <bsd.port.mk>
