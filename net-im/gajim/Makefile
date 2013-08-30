# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	0.15.4
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
USES=		gmake pathfix
USE_BZIP2=	yes
USE_DOS2UNIX=	src/plugins/plugins_i18n.py
USE_GNOME=	pygtk2
USE_PYTHON=	-2.7
USE_XORG=	x11 xext xscrnsaver
MAN1=		gajim.1 gajim-remote.1 gajim-history-manager.1

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AVAHI CRYPTO DBUS DOCS GUPNP KEYRING NLS SPELL
OPTIONS_DEFAULT=DBUS NLS SPELL
CRYPTO_DESC=	End to end encryption support
KEYRING_DESC=	Gnome Keyring support
SPELL_DESC=	Spell checking support

PORTDOCS=	AUTHORS ChangeLog README.html
OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MAVAHI}
RUN_DEPENDS+=	avahi-discover:${PORTSDIR}/net/py-avahi
.endif

.if ${PORT_OPTIONS:MDBUS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MGUPNP}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:${PORTSDIR}/net/gupnp-igd
.endif

.if ${PORT_OPTIONS:MCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MKEYRING}
USE_GNOME+=	pygnomedesktop
.endif

.if ${PORT_OPTIONS:MSPELL}
LIB_DEPENDS=	gtkspell:${PORTSDIR}/textproc/gtkspell
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

pre-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
