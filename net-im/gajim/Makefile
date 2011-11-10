# New ports collection makefile for:	gajim
# Date created:				Sun Nov 26 16:36:07 MSK 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.14.4
CATEGORIES=	net-im
MASTER_SITES=	http://www.gajim.org/downloads/0.14/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Gajim is a Jabber client based on a plugin system

LICENSE=	GPLv3

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_PORTVERSION}:${PORTSDIR}/databases/py-sqlite3

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	2.5+
USE_XORG=	x11 xext xscrnsaver

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	DBUS "Adds support for D-Bus (Desktop Bus)" On \
		NLS "Native Language Support via gettext utilities" On

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_DBUS)
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
.endif

MAN1=		gajim.1 gajim-remote.1 gajim-history-manager.1

EMOTICONS=	animated static static-big tango
ICONSETS=	dcraven gnome goojim gota jabberbulb sun transports wroop

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
