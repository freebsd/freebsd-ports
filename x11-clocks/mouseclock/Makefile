# Created by: FURUSAWA, Kazuhisa <kazu@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	mouseclock
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display the current time using the X root cursor

USES=		imake:notall
USE_XORG=	x11

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
