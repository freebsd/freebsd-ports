# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	0.16.1
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/0.16/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>0:${PORTSDIR}/net-im/py-nbxmpp

USES=		cpe dos2unix gmake pathfix python:2 tar:bzip2
USE_GNOME=	intltool pygtk2
USE_XORG=	x11 xext xscrnsaver

DOS2UNIX_FILES=	src/plugins/plugins_i18n.py
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AVAHI CRYPTO DBUS DOCS GUPNP NLS SPELL
OPTIONS_DEFAULT=DBUS NLS SPELL
OPTIONS_SUB=	yes

CRYPTO_DESC=	End to end encryption support
GUPNP_DESC=	UPnP IGD protocol support
SPELL_DESC=	Spell checking support

AVAHI_RUN_DEPENDS=	avahi-discover:${PORTSDIR}/net/py-avahi
CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:${PORTSDIR}/net/gupnp-igd
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell

PORTDOCS=	AUTHORS ChangeLog README.html
SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

pre-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/src
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/src

.include <bsd.port.mk>
