# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	0.15.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/0.15/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		dos2unix gmake pathfix
USE_BZIP2=	yes
DOS2UNIX_FILES=	src/plugins/plugins_i18n.py
USE_GNOME=	pygtk2
USE_PYTHON=	2
USE_XORG=	x11 xext xscrnsaver

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AVAHI CRYPTO DBUS DOCS GUPNP KEYRING NLS SPELL
OPTIONS_DEFAULT=DBUS NLS SPELL
OPTIONS_SUB=	yes
CRYPTO_DESC=	End to end encryption support
KEYRING_DESC=	Gnome Keyring support
SPELL_DESC=	Spell checking support

AVAHI_RUN_DEPENDS=	avahi-discover:${PORTSDIR}/net/py-avahi
CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:${PORTSDIR}/net/gupnp-igd
KEYRING_USE=		GNOME=pygnomedesktop
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell

PORTDOCS=	AUTHORS ChangeLog README.html

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-common_resolver.py
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

pre-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
