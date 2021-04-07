PORTNAME=	galculator
PORTVERSION=	2.1.4
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	math

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK-based scientific calculator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USES=		autoreconf gettext gmake gnome libtool localbase pkgconfig
USE_GNOME=	cairo intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_USE=		gnome=gtk20
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		gnome=gtk30

.include <bsd.port.mk>
