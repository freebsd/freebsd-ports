# Created by: ijliao
# $FreeBSD$

PORTNAME=	linsmith
PORTVERSION=	0.99.26
PORTREVISION=	1
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2 # (or later)

USES=		gettext pkgconfig
USE_GNOME=	libgnomeui libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/linsmith.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith.desktop ${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith_icon.xpm ${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
