# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	blam
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.6

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based RSS feed reader

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
USE_BZIP2=	yes
USE_X_PREFIX=   yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	blam.schemas

.include <bsd.port.mk>
