PORTNAME=	bamf
PORTVERSION=	0.5.6
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	BAMF Application Matching Framework
WWW=		https://launchpad.net/bamf

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.4.2:devel/py-lxml@${PY_FLAVOR}
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
	libstartup-notification-1.so:x11/startup-notification \
	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-runtime gmake gnome libtool pathfix \
		pkgconfig python:build vala:build xorg
USE_GNOME=	gtk30 glib20 introspection:build libwnck3 cairo gdkpixbuf
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-headless-tests \
	--disable-gtktest \
	--disable-gcov \
	--disable-gtk-doc-html \
	--without-html-dir \
	--enable-export-actions-menu=no \
	--enable-introspection=yes

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e 's| -Wl,-Bsymbolic-functions||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
