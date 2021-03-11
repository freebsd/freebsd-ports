# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://gajim.org/downloads/${DISTVERSION:R}/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ Jabber client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}css-parser>0:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>=1.0.2:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.12:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		cpe dos2unix gettext gnome python:3.7+ xorg
USE_PYTHON=	autoplist distutils noflavors
USE_GNOME=	pygobject3
USE_XORG=	x11 xext xscrnsaver

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes
DOS2UNIX_FILES=	gajim/plugins/plugins_i18n.py
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS DOCS SPELL OMEMO
OPTIONS_DEFAULT=DBUS SPELL OMEMO

SPELL_DESC=	Spell checking support
OMEMO_DESC=	OMEMO end-to-end encryption support

# GUPNP_DESC=	UPnP IGD protocol support

# net/py-avahi and net/gupnp-idg is python 2.x only right now
# AVAHI_RUN_DEPENDS=	avahi-discover:net/py-avahi@${PY_FLAVOR}
# GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:net/gupnp-igd@${PY_FLAVOR}

OMEMO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-axolotl>0:security/py-python-axolotl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

.include <bsd.port.mk>
