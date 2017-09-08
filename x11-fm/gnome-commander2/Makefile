# Created by: Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
# $FreeBSD$

PORTNAME=	gnome-commander
PORTVERSION=	1.6.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME/sources/gnome-commander/${PORTVERSION:R}
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	File manager for Gnome2

LICENSE=	GPLv2

LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique \
		libgnome-keyring.so:security/libgnome-keyring \
		libpopt.so:devel/popt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	meld:textproc/meld \
		yelp:x11/yelp

USES=		compiler:c++11-lang gettext gmake libtool pathfix pkgconfig python tar:xz
USE_GNOME=	cairo gdkpixbuf2 gnomedocutils gnomeprefix gnomevfs2 intltool libgnomeui
USE_XORG=	ice sm
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	gnome-commander-[0-9]*

OPTIONS_DEFINE=		CHM EXIV2 GSF POPPLER TAGLIB
OPTIONS_DEFAULT=	CHM EXIV2 GSF POPPLER TAGLIB

CHM_DESC=		CHM support via chmlib
CHM_LIB_DEPENDS=	libchm.so:misc/chmlib
CHM_CONFIGURE_WITH=	libchm
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CONFIGURE_WITH=	exiv2
GSF_DESC=		OLE and ODF support via libgsf
GSF_LIB_DEPENDS=	libgsf-1.so:devel/libgsf
GSF_CONFIGURE_WITH=	libgsf
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_CONFIGURE_WITH=	poppler
TAGLIB_DESC=		Audio metadata support via taglib
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_WITH=	taglib

post-patch:
	@${REINPLACE_CMD} -e \
		's|="-lpython|="-L$$PY_EXEC_PREFIX/lib -lpython|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
