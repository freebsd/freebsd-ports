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

PLIST_FILES=	bin/xwlans
USE_XORG=	x11

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
