# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	0.16.8
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/0.16/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>0:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe dos2unix gmake localbase pathfix python:2.7 tar:bzip2
USE_GNOME=	intltool pygtk2
USE_XORG=	x11 xext xscrnsaver

DOS2UNIX_FILES=	src/plugins/plugins_i18n.py
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	AVAHI CRYPTO DBUS DOCS GUPNP NLS SPELL
OPTIONS_DEFAULT=DBUS SPELL
OPTIONS_SUB=	yes

CRYPTO_DESC=	End to end encryption support
GUPNP_DESC=	UPnP IGD protocol support
SPELL_DESC=	Spell checking support

AVAHI_RUN_DEPENDS=	avahi-discover:net/py-avahi@${PY_FLAVOR}
CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:net/gupnp-igd
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

PORTDOCS=	AUTHORS ChangeLog README
SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

pre-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/src
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/src

.include <bsd.port.mk>
