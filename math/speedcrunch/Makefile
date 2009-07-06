# New ports collection makefile for:	speedcrunch
# Date created:		27 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	speedcrunch
DISTVERSION=	0.10.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A desktop calculator for power users

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build gui xml
USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	src
CMAKE_USE_PTHREAD=	yes

MAKE_JOBS_SAFE=	yes

LRELEASE_CMD=	${LOCALBASE}/bin/lrelease-qt4
LRELEASE_ARGS=	-compress -silent

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/src/i18n && ${LRELEASE_CMD} ${LRELEASE_ARGS} *.ts
.else
	${REINPLACE_CMD} -e '/speedcrunch_TRANSLATIONS/d' ${WRKSRC}/src/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/src/gui/mainwindow.cpp

.include <bsd.port.mk>
