# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtklp
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=	.src
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface to cups

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		autoreconf gettext libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="GtkLP" "" "${PORTNAME}" "${PORTNAME}" "System;GTK;" ""

post-install:
.for i in 16 24 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/libgtklp/icons && ${INSTALL_DATA} ${i}x${i}.xpm \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtklp.xpm)
.endfor

.include <bsd.port.mk>
