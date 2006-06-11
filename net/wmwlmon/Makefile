# New ports collection makefile for:	wmwlmon
# Date created:				04 May 2006
# Whom:					Marcus Glocker <marcus@nazgul.ch>
#
# $FreeBSD$
#

PORTNAME=	wmwlmon
PORTVERSION=	0.9
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.nazgul.ch/dev/ \
		http://dougbarton.us/Downloads/
DISTNAME=	wmwlmon-${PORTVERSION}

MAINTAINER=	marcus@nazgul.ch
COMMENT=	DockApp showing the state of a wireless network device

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		wmwlmon.1
PLIST_FILES=	bin/wmwlmon

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600100
BROKEN=	Needs WLAN infrastructure from 6.0-RELEASE or newer
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwlmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwlmon.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
