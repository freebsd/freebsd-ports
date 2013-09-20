# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	wmtunlo
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.gnu-darwin.org/distfiles/ \
		http://cvsup.theplanet.com/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Falling-down-a-tunnel dockapp

USE_XORG=	x11 xpm xextproto
ALL_TARGET=	wmtunlo

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtunlo ${PREFIX}/bin
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
