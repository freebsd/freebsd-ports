# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	1.8.9
CATEGORIES=	www
MASTER_SITES=	https://github.com/QupZilla/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	-qt5
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	matthew@reztek.cz
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.3.so:textproc/hunspell

CONFLICTS_INSTALL=	${PORTNAME}-qt4*

USES=		desktop-file-utils execinfo pkgconfig qmake tar:xz
USE_QT5=	core concurrent gui network script webkit x11extras xml \
		buildtools_build linguisttools_build \
		imageformats_run sql-sqlite3_run
USE_XORG=	x11
USE_OPENSSL=	yes
CONFIGURE_ENV=	QUPZILLA_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DBUS DEBUG GNOMEKEYRING KWALLET
OPTIONS_DEFAULT=DBUS
OPTIONS_SUB=	yes

DBUS_USE=		QT5=dbus
DBUS_CONFIGURE_ENV_OFF=	DISABLE_DBUS="true"

GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring
GNOMEKEYRING_CONFIGURE_ENV=	GNOME_INTEGRATION="true"

KWALLET_USE=		KDE5=wallet
KWALLET_CONFIGURE_ENV=	KDE_INTEGRATION="true"

.include <bsd.port.options.mk>

# work around for build failure in test plugin (single source file target)
.if ${PORT_OPTIONS:MDEBUG}
MAKE_JOBS_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/tests/autotests/qztoolstest.cpp \
		${WRKSRC}/src/lib/plugins/qtwebkit/spellcheck/speller.cpp
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/install.pri \
		${WRKSRC}/src/defines.pri \
		${WRKSRC}/src/lib/plugins/plugins.cpp

.include <bsd.port.mk>
