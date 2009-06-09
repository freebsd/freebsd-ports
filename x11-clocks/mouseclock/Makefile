# New ports collection makefile for:	mouseclock
# Date created:		26 August 1997
# Whom:			FURUSAWA, Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mouseclock
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks

MAINTAINER=	kazu@jp.freebsd.org
COMMENT=	Display the current time using the X root cursor

USE_GMAKE=	yes
USE_IMAKE=	yes
USE_XORG=	x11 xext
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=	yes

post-configure:
	@${TOUCH} ${WRKSRC}/mouseclock.man

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
