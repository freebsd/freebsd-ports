# Created by: andreas@syndrom23.de
# $FreeBSD$

PORTNAME=	eiciel
PORTVERSION=	0.9.8.2
CATEGORIES=	sysutils security
MASTER_SITES=	http://rofi.roger-ferrer.org/eiciel/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME-based ACL editor, with integration into Nautilus

LICENSE=	GPLv2

DEPRECATED=	nautilus will be updated to the 3.x version which is not compatible with 2.x
EXPIRATION_DATE=2014-04-10

USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtkmm24 libgnome nautilus2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-gnome-version=2 \
		--with-nautilus-extensions-dir=${PREFIX}/lib/nautilus/extensions-2.0

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
