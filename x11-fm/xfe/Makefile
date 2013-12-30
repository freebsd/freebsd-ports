# Created by: ptiJo
# $FreeBSD$

PORTNAME=	xfe
PORTVERSION=	1.37
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast MS-Explorer like file manager for X

LICENSE=	GPLv2

LIB_DEPENDS=	libFOX-1.6.so:${PORTSDIR}/x11-toolkits/fox16

OPTIONS_DEFINE=	NLS

USE_XORG=	xft
USE_GNOME=	intltool
USES=		gettext gmake pathfix
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/share/xfe|${DATADIR}|g' \
		${WRKSRC}/src/XFileExplorer.cpp \
		${WRKSRC}/src/help.h \
		${WRKSRC}/src/xfedefs.h
	@${REINPLACE_CMD} -e 's|freetype/||g' ${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
