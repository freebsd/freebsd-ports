# $FreeBSD$

PORTNAME=	Kvantum
DISTVERSIONPREFIX=	V
DISTVERSION=	0.10.7
PORTREVISION=	2
CATEGORIES=	x11-themes

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	SVG-based theme engine for Qt, KDE and LXQt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_PKGNAMESUFFIX=	-qt4
qt5_PKGNAMESUFFIX=	-qt5

qt4_PLIST=	pkg-plist.qt4
qt5_PLIST=	pkg-plist.qt5

USES=		compiler:c++11-lang qmake
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	tsujan

.if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		corelib gui svg rcc_build uic_build moc_build
.elif ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		core gui svg widgets x11extras buildtools_build \
		linguisttools_build
.endif

WRKSRC_SUBDIR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' ${WRKSRC}/style/style.pro
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' -e 's|--no-preserve=mode||g' \
		${WRKSRC}/themes/themes.pro

.include <bsd.port.mk>
