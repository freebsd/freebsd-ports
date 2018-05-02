# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
DISTVERSION=	1.0.2
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/1.0/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ Jabber client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nbxmpp>=0.6.5:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.12:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe dos2unix python:3.5+ tar:bzip2
USE_PYTHON=	autoplist distutils
USE_GNOME=	intltool pygobject3
USE_XORG=	x11 xext xscrnsaver

DOS2UNIX_FILES=	gajim/plugins/plugins_i18n.py
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	CRYPTO DBUS DOCS NLS SPELL
OPTIONS_DEFAULT=DBUS SPELL

CRYPTO_DESC=	End to end encryption support
SPELL_DESC=	Spell checking support

# GUPNP_DESC=	UPnP IGD protocol support

# net/py-avahi and net/gupnp-idg is python 2.x only right now
# AVAHI_RUN_DEPENDS=	avahi-discover:net/py-avahi@${PY_FLAVOR}
# GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:net/gupnp-igd@${PY_FLAVOR}

CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

.include <bsd.port.mk>
