PORTNAME=	gajim
DISTVERSION=	2.6.0
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
LIB_DEPENDS=	libgsound.so:audio/gsound \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}css-parser>0:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emoji>=2.6.0:misc/py-emoji@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>=7.4.0:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}omemo-dr>=1.2.0:security/py-omemo-dr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>=1.16.0:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.3.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}socksio>0:net/py-socksio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysequoia>=0.1.33:security/py-pysequoia@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}truststore>0:security/py-truststore@${PY_FLAVOR} \
		pango>0:x11-toolkits/pango

USES=		cpe gettext gnome python:3.12+ xorg gstreamer
USE_GSTREAMER=	core good bad libav rust
USE_GNOME=	gtksourceview5 libadwaita pygobject3
USE_PYTHON=	autoplist cryptography noflavors pep517 pytest
USE_XORG=	x11 xext xscrnsaver

NO_ARCH=	yes

OPTIONS_DEFINE=		AVCALLS DBUS LIBSECRET SENTRY SPELLING GPS DISTRO
OPTIONS_DEFAULT=	DBUS AVCALLS LIBSECRET SPELLING GPS DISTRO

AVCALLS_DESC=		Audio/Video calling support
LIBSECRET_DESC=		GNOME Keyring or KDE secure password storage
OPENPGP_DESC=		GPG encryption per XEP-0373
SENTRY_DESC=		Sentry error reporting to dev.gajim.org.
SPELLING_DESC=		Enables spell checking
GPS_DESC=		Enables location sharing
DISTRO_DESC=		Enables OS info in device info

AVCALLS_RUN_DEPENDS=	farstream>0:net-im/farstream
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
LIBSECRET_RUN_DEPENDS=	libsecret>0:security/libsecret \
			gnome-keyring>=0:security/gnome-keyring
SENTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR}
SPELLING_LIB_DEPENDS=	libspelling-1.so:x11-toolkits/libspelling
GPS_LIB_DEPENDS=	libgeoclue-2.so:net/geoclue
DISTRO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR}

.include <bsd.port.mk>
