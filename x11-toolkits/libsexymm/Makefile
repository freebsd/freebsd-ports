# Ports collection makefile for:	libsexymm
# Date created:				2005-11-07
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	libsexymm
PORTVERSION=	0.1.9
PORTREVISION=	3
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ bindings for libsexy

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		sexy:${PORTSDIR}/x11-toolkits/libsexy

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
