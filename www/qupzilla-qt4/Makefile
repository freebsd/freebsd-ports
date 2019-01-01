# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	1.8.9
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	https://github.com/QupZilla/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	-qt4
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell

CONFLICTS_INSTALL=	${PORTNAME}-qt5*

USES=		desktop-file-utils pkgconfig qmake qt:4 ssl tar:xz
USE_QT=		corelib gui network script sql webkit xml \
		linguisttools_build moc_build rcc_build uic_build \
		imageformats_run sql-sqlite3_run
USE_XORG=	x11
CONFIGURE_ENV=	QUPZILLA_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DBUS DEBUG GNOMEKEYRING
OPTIONS_DEFAULT=DBUS
OPTIONS_SUB=	yes

DBUS_USES=	qt:4
DBUS_USE=		QT=dbus
DBUS_CONFIGURE_ENV_OFF=	DISABLE_DBUS="true"

GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring
GNOMEKEYRING_CONFIGURE_ENV=	GNOME_INTEGRATION="true"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/tests/autotests/qztoolstest.cpp \
		${WRKSRC}/src/lib/plugins/qtwebkit/spellcheck/speller.cpp
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/install.pri \
		${WRKSRC}/src/defines.pri \
		${WRKSRC}/src/lib/plugins/plugins.cpp
	@${REINPLACE_CMD} -e 's|%%KDE4_INC%%|${LOCALBASE}/include/kde4|g' \
		${WRKSRC}/src/plugins/KWalletPasswords/KWalletPasswords.pro

.include <bsd.port.mk>
