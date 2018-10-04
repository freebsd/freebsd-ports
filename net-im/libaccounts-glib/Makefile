# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libaccounts-glib
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-tests --enable-gtk-doc
INSTALL_TARGET=	install-strip

USES=		autoreconf gmake gnome libtool pathfix pkgconfig python sqlite:3
USE_GNOME=	pygobject3 introspection libxml2
USE_PYTHON=	py3kplist
CFLAGS_powerpc64=	-Wno-error

# GitLab variables.
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	00254a604a7c7bd38c41794a80ad8930e90f21aa

pre-configure:
	cd ${WRKSRC} && gtkdocize --copy --flavour no-tmpl

.include <bsd.port.mk>
