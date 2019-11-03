# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtklp
DISTVERSION=	1.3.4
DISTVERSIONSUFFIX=	.src
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	m.ne@gmx.net
COMMENT=	GTK interface to cups

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gettext gnome libtool pkgconfig xorg
USE_GNOME=	cairo gtk20
INSTALLS_ICONS=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="GtkLP" "" "${PORTNAME}" "${PORTNAME}" "System;GTK;" ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
.for i in 16 24 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/libgtklp/icons && ${INSTALL_DATA} ${i}x${i}.xpm \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtklp.xpm)
.endfor

.include <bsd.port.mk>
