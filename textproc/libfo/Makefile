PORTNAME=	libfo
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter library for xmlroff
WWW=		http://xmlroff.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/catalog.xml:textproc/docbook-xsl \
		xmlcatmgr:textproc/xmlcatmgr
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfreetype.so:print/freetype2

CONFLICTS_INSTALL=	xmlroff-0.6.[12] xmlroff-0.6.2_[12345]

USES=		autoreconf gettext gmake gnome localbase libtool pathfix pkgconfig
USE_GNOME=	libxslt libxml2 glib20 pango \
		librsvg2 gdkpixbuf
USE_GITHUB=	yes
GH_PROJECT=	xmlroff
GH_ACCOUNT=	xmlroff
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	xmlroff
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-gp
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
	    ${WRKSRC}/libfo/fo-libfo-basic.h

.include <bsd.port.mk>
