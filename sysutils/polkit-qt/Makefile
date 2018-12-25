# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
DISTVERSIONPREFIX=	1-
DISTVERSION=	0.112.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/
PKGNAMESUFFIX=	${FLAVOR:C/qt//}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt${FLAVOR:C/qt//} wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake gnome pkgconfig tar:bzip2
USE_GNOME=	glib20
CMAKE_OFF=	BUILD_EXAMPLES  \
		BUILD_TEST

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		kde:4 qt:4
USE_KDE=	automoc4
USE_QT=		corelib dbus gui \
		qmake_build moc_build rcc_build uic_build
CMAKE_ON+=	USE_QT4
CMAKE_OFF+=	USE_QT5
QTVER_SUFFIX=	# empty
.  else
USES+=		compiler:c++11-lang qt:5
USE_QT=		core dbus gui widgets buildtools_build qmake_build
CMAKE_ON+=	USE_QT5
CMAKE_OFF+=	USE_QT4
QTVER_SUFFIX=	5
.  endif

USE_LDCONFIG=	yes

PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
