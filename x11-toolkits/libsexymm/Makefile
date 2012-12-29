# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libsexymm
PORTVERSION=	0.1.9
PORTREVISION=	6
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	C++ bindings for libsexy

LICENSE=	LGPL21

LIB_DEPENDS=	gtkmm-2:${PORTSDIR}/x11-toolkits/gtkmm24 \
		sexy:${PORTSDIR}/x11-toolkits/libsexy

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
