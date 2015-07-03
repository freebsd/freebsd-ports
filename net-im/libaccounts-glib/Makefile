# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libaccounts-glib
PORTVERSION=	1.18
CATEGORIES=	net-im
MASTER_SITES=	https://drive.google.com/uc?export=download&id=0B8fX9XOwH_g4U1NzNmg0cWoxNGM&dummy= \
		LOCAL/rakuco

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

GNU_CONFIGURE=	YES
# The line below is a hack required when the port is configure either without
# devel/libcheck installed or with --disable-tests.
# A proper fix has been submitted upstream:
# https://gitlab.com/accounts-sso/libaccounts-glib/merge_requests/1
CONFIGURE_ENV=	HAVE_GCOV_FALSE='\#'
CONFIGURE_ARGS=	--disable-tests
INSTALL_TARGET=	install-strip

USES=		gmake libtool pathfix pkgconfig python
USE_GNOME=	pygobject3 introspection libxml2

.include <bsd.port.mk>
