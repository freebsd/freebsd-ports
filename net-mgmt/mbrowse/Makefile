# Created by: Mark Pulford <mark@kyne.com.au>

PORTNAME=	mbrowse
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	eg@fbsd.lt
COMMENT=	SNMP MIB Browser for X

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig ssl
USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-snmp-prefix=${PREFIX} --with-snmp-type=net

PLIST_FILES=	bin/mbrowse

.include <bsd.port.mk>
