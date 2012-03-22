# New ports collection makefile for:	gajim
# Date created:				Sun Nov 26 16:36:07 MSK 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.gajim.org/downloads/0.15/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Gajim is a Jabber client based on a plugin system

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

FETCH_ARGS=	-Fpr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	-2.7
USE_XORG=	x11 xext xscrnsaver

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	CRYPTO "End to end encryption support" Off \
		DBUS "Adds support for D-Bus (Desktop Bus)" On \
		KEYRING "Gnome Keyring support" Off \
		NLS "Native Language Support via gettext utilities" On \
		SPELL "Spell checking support" On

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_DBUS)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
.endif

.if defined(WITH_CRYPTO)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto
.endif

.if defined(WITH_KEYRING)
USE_GNOME+=	pygnomedesktop
.endif

.if defined(WITH_SPELL)
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
.endif

MAN1=		gajim.1 gajim-remote.1 gajim-history-manager.1

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
