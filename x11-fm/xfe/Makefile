# Created by: ptiJo
# $FreeBSD$

PORTNAME=	xfe
PORTVERSION=	1.35
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_XORG=	xft
USE_GNOME=	gnomehack intltool
USES=		gettext gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -g -O0
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

MAN1=		xfe.1 xfi.1 xfp.1 xfv.1 xfw.1

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/share/xfe|${DATADIR}|g' \
		${WRKSRC}/src/XFileExplorer.cpp \
		${WRKSRC}/src/help.h \
		${WRKSRC}/src/xfedefs.h

.include <bsd.port.mk>
