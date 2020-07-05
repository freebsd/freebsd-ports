# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	bamf
PORTVERSION=	0.5.4
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/280921055/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	BAMF Application Matching Framework

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	vapigen:lang/vala \
	${PYTHON_PKGNAMEPREFIX}lxml>=4.4.2:devel/py-lxml@${PY_FLAVOR}
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
	libstartup-notification-1.so:x11/startup-notification

USES=		compiler:c11 gettext-runtime gmake gnome libtool pathfix \
		pkgconfig python:3.5+,build xorg
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 introspection:build libwnck3 cairo gdkpixbuf2
USE_XORG=	x11
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--disable-headless-tests \
	--disable-gtktest \
	--disable-gcov \
	--disable-gtk-doc-html \
	--without-html-dir \
	--enable-export-actions-menu=no \
	--enable-introspection=yes

post-patch:
	${REINPLACE_CMD} -e 's| -Wl,-Bsymbolic-functions||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
