PORTNAME=	gajim
DISTVERSION=	2.2.0
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
LIB_DEPENDS=	libgsound.so:audio/gsound \
		libsoup-3.0.so:devel/libsoup3 \
		libspelling-1.so:x11-toolkits/libspelling
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.16.0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}css-parser>0:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emoji>=2.6.0:misc/py-emoji@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>=6.2.0<7.0.0:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}omemo-dr>=1.0.0:security/py-omemo-dr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.3.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		pango>0:x11-toolkits/pango \
		gnome-keyring>=0:security/gnome-keyring

USES=		cpe gettext gnome python:3.11+ xorg
USE_GNOME=	gtksourceview5 pygobject3
USE_PYTHON=	autoplist cryptography noflavors pep517 pytest
USE_XORG=	x11 xext xscrnsaver

NO_ARCH=	yes

OPTIONS_DEFINE=		AVCALLS DBUS DOCS LIBSECRET OPENPGP SENTRY VOICEMESSAGES
OPTIONS_DEFAULT=	DBUS OPENPGP

AVCALLS_DESC=		Audio/Video calling support
LIBSECRET_DESC=		GNOME Keyring or KDE secure password storage
OPENPGP_DESC=		GPG encryption per XEP-0373
SENTRY_DESC=		Sentry error reporting to dev.gajim.org.
VOICEMESSAGES_DESC=	Voice messages support

AVCALLS_RUN_DEPENDS=	farstream>0:net-im/farstream
AVCALLS_USES=		gstreamer
AVCALLS_USE=		GSTREAMER=core libav rust ugly
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
LIBSECRET_RUN_DEPENDS=	libsecret>0:security/libsecret
OPENPGP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}
SENTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR}
VOICEMESSAGES_USES=	gstreamer
VOICEMESSAGES_USE=	GSTREAMER=core good

.include <bsd.port.mk>
