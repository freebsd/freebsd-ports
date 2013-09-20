# Created by: ijliao
# $FreeBSD$

PORTNAME=	linsmith
PORTVERSION=	0.99.26
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2 # (or later)

USES=		gettext pkgconfig
USE_GNOME=	libgnomeui libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/linsmith.desktop

post-install:
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith.desktop ${DESKTOPDIR})
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} linsmith_icon.xpm ${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
