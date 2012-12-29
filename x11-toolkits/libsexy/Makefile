# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libsexy
PORTVERSION=	0.1.11
PORTREVISION=	6
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Extension widgets for GTK+

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GNOME=	gnomehack lthack gtk20 libxml2
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
