# New ports collection makefile for:	mouseclock
# Date created:		26 August 1997
# Whom:			FURUSAWA, Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mouseclock
PORTVERSION=	1.0
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks

MAINTAINER=	kazu@jp.freebsd.org

USE_GMAKE=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES= yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mouseclock
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/mouseclock
.endif

.include <bsd.port.mk>
