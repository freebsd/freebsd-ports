# Created by: ijliao
# $FreeBSD$

PORTNAME=	gambit
DISTVERSION=	16.0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PORTVERSION:R:R}/${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of tools for doing computation in game theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gnome
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_WX=		3.0
USE_CXXSTD=	c++11
WX_CONF_ARGS=	absolute

post-install:
	${INSTALL_DATA} ${WRKSRC}/gambit.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/gui/bitmaps/gambit.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
