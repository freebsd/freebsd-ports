PORTNAME=	gajim
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://gajim.org/downloads/${DISTVERSION:R}/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK Jabber client
WWW=		https://gajim.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}css-parser>0:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>=1.0.2:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}omemo-dr>0:security/py-omemo-dr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emoji>0:misc/py-emoji@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR}
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libspelling-1.so:x11-toolkits/libspelling \
		libgsound.so:audio/gsound

USES=		cpe gettext gnome python:3.11+ xorg
USE_PYTHON=	autoplist cryptography pep517 noflavors
USE_GNOME=	gtksourceview5 pygobject3
USE_XORG=	x11 xext xscrnsaver

NO_ARCH=	yes

OPTIONS_DEFINE=	DBUS DOCS OPENGPG
OPTIONS_DEFAULT=DBUS OPENGPG

OPENGPG_DESC=	GPG encryption per XEP-0373

DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
OPENGPG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}

.include <bsd.port.mk>
