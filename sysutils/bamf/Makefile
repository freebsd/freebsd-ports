# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	bamf
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/140100218/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	BAMF Application Matching Framework

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>=2.8.0:${PORTSDIR}/textproc/py-libxml2 \
	${PYTHON_PKGNAMEPREFIX}libxslt>=1.1.28:${PORTSDIR}/textproc/py-libxslt

USES=	pkgconfig gmake pathfix libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 introspection:build libwnck3
USE_PYTHON=	2
USE_XORG=	x11

CONFIGURE_ARGS+=--disable-webapps \
	--disable-headless-tests \
	--disable-gtktest \
	--disable-gtk-doc-html \
	--without-html-dir

.include <bsd.port.mk>
