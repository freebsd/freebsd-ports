# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libaccounts-glib
DISTVERSION=	1.25
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala \
		checkmk:devel/check
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gnome libtool meson pathfix pkgconfig python sqlite:3
USE_GNOME=	pygobject3 introspection libxml2
USE_PYTHON=	py3kplist
CFLAGS_powerpc64=	-Wno-error
CFLAGS_powerpc64le=	-Wno-error

CONFIGURE_ARGS=	-Dtests=false

INSTALL_TARGET=	install-strip

# GitLab variables.
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	886a80b3ba975d8a59a6500ade2b1debb552660c

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
