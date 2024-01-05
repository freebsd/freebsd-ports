PORTNAME=	libaccounts-glib
DISTVERSION=	1.26
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms
WWW=		https://gitlab.com/accounts-sso

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	checkmk:devel/check
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gnome libtool meson pathfix pkgconfig python sqlite:3 vala:build
USE_GNOME=	pygobject3 introspection libxml2
USE_PYTHON=	py3kplist

CONFIGURE_ARGS=	-Dtests=false

INSTALL_TARGET=	install-strip

# GitLab variables.
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	d31d74997c8524cac862a2c5f0cd902f99a39fc6

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
