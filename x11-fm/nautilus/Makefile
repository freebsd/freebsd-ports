# New ports collection makefile for:    nautilus
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus
PORTVERSION=	1.0.6
PORTREVISION=	9
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME file manager and graphical shell developed by Eazel

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	medusa.0:${PORTSDIR}/sysutils/medusa \
		freetype.9:${PORTSDIR}/print/freetype2 \
		eel.0:${PORTSDIR}/x11-toolkits/eel

.if defined(WITH_FAM) || exists(${LOCALBASE}/lib/libfam.so.0)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNOME_DESKTOP_VERSION=1
USE_GNOME=	gnomehack gnomeprefix gnomehier libpanel libghttp bonobo \
		gnomevfs
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -fno-rtti -fno-exceptions" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2 \
		--disable-mozilla-component

MAN1=		nautilus-xml-migrate.1

.include <bsd.port.mk>
