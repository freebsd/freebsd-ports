PORTNAME=	vala
DISTVERSION=	${_VALA_VERSION}
PORTEPOCH=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code
WWW=		https://wiki.gnome.org/Projects/Vala

LICENSE=	LGPL21

TEST_DEPENDS=	bash:shells/bash \
		dbus>0:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		bison cpe gettext-runtime gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz\
		vala:no_depend
USE_GNOME=	glib20 gnomeprefix introspection:build libxslt:build
CPE_VENDOR=	gnome
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-valadoc
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

PLIST_SUB=	VALA_LIB_VERSION=${_VALA_LIB_VERSION}

.include <bsd.port.mk>
