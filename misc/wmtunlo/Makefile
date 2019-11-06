# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	wmtunlo
PORTVERSION=	0.1.3
PORTREVISION=	4
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.gnu-darwin.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Falling-down-a-tunnel dockapp

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	x11 xpm xorgproto
ALL_TARGET=	wmtunlo

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtunlo ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
