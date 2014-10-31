# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	1.8.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/QupZilla/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern web browser based on WebKit core and Qt Framework

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		desktop-file-utils pkgconfig qmake tar:xz
USE_QT4=	corelib gui moc_build rcc_build uic_build webkit \
		xml script sql network imageformats_run linguist_build
QMAKE_ENV=	QUPZILLA_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS GNOMEKEYRING KWALLET
OPTIONS_DEFAULT=DBUS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEKEYRING}
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
QMAKE_ENV+=	GNOME_INTEGRATION="true"
.endif

.if ${PORT_OPTIONS:MKWALLET}
LIB_DEPENDS+=	libkdeui.so:${PORTSDIR}/x11/kdelibs4
QMAKE_ENV+=	KDE_INTEGRATION="true"
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
QMAKE_ENV+=	DISABLE_DBUS="true"
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
