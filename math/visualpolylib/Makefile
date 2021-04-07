PORTNAME=	visualpolylib
DISTVERSION=	0.9
DISTVERSIONSUFFIX=	e
CATEGORIES=	math
MASTER_SITES=	http://icps.u-strasbg.fr/polylib/download/
DISTNAME=	${PORTNAME}.${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization program for PolyLib

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libpolylibgmp.so:math/polylib

USES=		gettext-runtime gmake gnome pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-polylib=${LOCALBASE}/lib/libpolylibgmp.so
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango

CFLAGS+=	-fcommon # notified the maontainer via e-mail on Sep 19, 2020

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
