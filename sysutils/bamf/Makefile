# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	bamf
PORTVERSION=	0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/148968286/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	BAMF Application Matching Framework

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
	${PYTHON_PKGNAMEPREFIX}libxml2>=2.8.0:${PORTSDIR}/textproc/py-libxml2 \
	${PYTHON_PKGNAMEPREFIX}libxslt>=1.1.28:${PORTSDIR}/textproc/py-libxslt
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		pkgconfig gmake pathfix libtool python:2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 introspection:build libwnck3
USE_XORG=	x11

CONFIGURE_ARGS+=--disable-webapps \
	--disable-headless-tests \
	--disable-gtktest \
	--disable-gtk-doc-html \
	--without-html-dir

post-patch:
	${FIND} ${WRKSRC} -type f -name 'Makefile.in' \
		| ${XARGS} ${REINPLACE_CMD} -e 's| -Wl,-Bsymbolic-functions||'

.include <bsd.port.mk>
