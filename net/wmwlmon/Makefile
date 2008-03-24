# New ports collection makefile for:	wmwlmon
# Date created:				04 May 2006
# Whom:					Marcus Glocker <marcus@nazgul.ch>
#
# $FreeBSD$
#

PORTNAME=	wmwlmon
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.nazgul.ch/dev/ \
		http://dougbarton.us/Downloads/
DISTNAME=	wmwlmon-${PORTVERSION}

MAINTAINER=	marcus@nazgul.ch
COMMENT=	DockApp showing the state of a wireless network device

USE_XORG=	x11 xpm

MAN1=		wmwlmon.1
PLIST_FILES=	bin/wmwlmon

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600100
BROKEN=	Needs WLAN infrastructure from 6.0-RELEASE or newer
.elif ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.presed
	${SED} -e 's#/usr/X11R6#${X11BASE}#g' \
	    -e 's#/usr/local#${LOCALBASE}#g' \
	    ${WRKSRC}/Makefile.presed > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwlmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwlmon.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
