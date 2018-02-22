# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	bamf
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/280921055/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BAMF Application Matching Framework

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	vapigen:lang/vala \
	${PYTHON_PKGNAMEPREFIX}libxml2>=2.8.0:textproc/py-libxml2@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}libxslt>=1.1.28:textproc/py-libxslt@${PY_FLAVOR}
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
	libdbus-glib-1.so:devel/dbus-glib \
	libstartup-notification-1.so:x11/startup-notification

USES=		gettext-runtime gmake libtool pathfix pkgconfig python:2.7
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 introspection:build libwnck3 cairo gdkpixbuf2
USE_XORG=	x11
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--disable-headless-tests \
	--disable-gtktest \
	--disable-gtk-doc-html \
	--without-html-dir

post-patch:
	${FIND} ${WRKSRC} -type f -name 'Makefile.in' \
		| ${XARGS} ${REINPLACE_CMD} -e 's| -Wl,-Bsymbolic-functions||'

.include <bsd.port.mk>
