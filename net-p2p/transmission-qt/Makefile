# $FreeBSD$

PORTREVISION=	3
PKGNAMESUFFIX=	-${FLAVOR}

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_CONFLICTS_INSTALL=	transmission-qt5
qt5_CONFLICTS_INSTALL=	transmission-qt4

.if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES=		qt:4
NLS_USES=	gettext-runtime:run qt:4
USE_QT=		moc_build linguisttools_build qmake_build rcc_build \
		uic_build corelib dbus gui network xml
CMAKE_OFF+=	USE_QT5
.endif

.if ${FLAVOR} == qt5
USES=		qt:5
NLS_USES=	gettext-runtime:run qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core dbus gui network widgets
CMAKE_ON=	USE_QT5
.endif

USES+=		compiler:c++11-lang

MASTERDIR=	${.CURDIR}/../transmission-cli
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

SLAVEPORT=	qt

.include "${MASTERDIR}/Makefile"
