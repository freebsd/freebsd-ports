# ex:ts=8
# Ports collection Makefile for:  rclock
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11/rxvt-devel
# when you upgrade rxvt.  These ports all use the same distfile.
#

PORTNAME=	rclock
PORTVERSION=	2.7.10
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	SF/rxvt/rxvt-dev/${PORTVERSION}
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analog clock for X w/appointment reminder and mail notification

USE_XORG=	x11 xau xdmcp ice xpm xv
GNU_CONFIGURE=	yes
ALL_TARGET=	clock
MAN1=		rclock.1

PLIST_FILES=	bin/rclock

CPPFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'

post-patch:
	@${REINPLACE_CMD} \
		's|^subdirs =.*$$|subdirs = rclock|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
