# Ports collection makefile for:	libsexymm
# Date created:				2005-11-07
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		libsexymm
PORTVERSION=		0.1.7
CATEGORIES=		x11-toolkits devel
MASTER_SITES=		http://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=		andreas@syndrom23.de
COMMENT=		C++ bindings for libsexy

LIB_DEPENDS=		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
			sexy:${PORTSDIR}/x11-toolkits/libsexy

USE_GNOME=		gnomehack
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_SHLIB=		yes
USE_X_PREFIX=		yes
USE_GCC=		3.4

.include <bsd.port.mk>
