# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	1.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.qupzilla.com/uploads/
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Modern web browser based on WebKit core and Qt Framework

LICENSE=	GPLv3

BROKEN=		Fetch fails

LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		desktop-file-utils pkgconfig qmake
USE_QT4=	gui moc_build rcc_build uic_build webkit \
		dbus xml script sql network imageformats_run linguist_build
QMAKE_ENV=	QUPZILLA_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/tests/autotests/qztoolstest.cpp \
		${WRKSRC}/src/lib/plugins/qtwebkit/spellcheck/speller.cpp
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/install.pri \
		${WRKSRC}/src/defines.pri \
		${WRKSRC}/src/lib/plugins/plugins.cpp

.include <bsd.port.mk>
