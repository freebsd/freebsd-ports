# Created by: ijliao
# $FreeBSD$

PORTNAME=	linsmith
PORTVERSION=	0.99.30
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2+

USES=		gettext pkgconfig
USE_GNOME=	libgnomeui libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR}

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Categories/s|Application;|| ; \
		 /^Icon/s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/linsmith.desktop

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} linsmith.desktop \
		${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} linsmith_icon.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/linsmith)

.include <bsd.port.mk>
