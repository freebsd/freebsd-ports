# New ports collection makefile for:	bakery_gnomeui
# Date created:				28 Nov 2003
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bakery_gnomeui
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bakery

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Bakery C++ Application Framework extention for GNOME

LIB_DEPENDS=	bakery-2.0:${PORTSDIR}/x11-toolkits/bakery \
		gnomeuimm-2.0:${PORTSDIR}/x11-toolkits/libgnomeuimm

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
