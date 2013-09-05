# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	1.4.4
CATEGORIES=	www
MASTER_SITES=	http://www.qupzilla.com/uploads/
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Modern web browser based on WebKit core and Qt Framework

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell

HAS_CONFIGURE=	yes
USE_QT4=	gui moc_build qmake_build rcc_build uic_build webkit \
		dbus xml script sql network imageformats linguist_build
MAKE_ENV+=	QUPZILLA_PREFIX=${PREFIX}/ USE_LIBPATH=${PREFIX}/lib/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} QupZilla.pro

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/tests/autotests/qztoolstest.cpp \
		${WRKSRC}/src/lib/plugins/qtwebkit/spellcheck/speller.cpp
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/install.pri

.include <bsd.port.mk>
