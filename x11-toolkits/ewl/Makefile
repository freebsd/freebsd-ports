# New ports collection makefile for:	ewl
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ewl
PORTVERSION=	0.0.4.004
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Enlightened Widget Library

LIB_DEPENDS=	embryo.9:${PORTSDIR}/lang/embryo \
		edb.1:${PORTSDIR}/databases/edb \
		evas.1:${PORTSDIR}/graphics/evas \
		edje.5:${PORTSDIR}/graphics/edje \
		ecore.1:${PORTSDIR}/x11/ecore

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
