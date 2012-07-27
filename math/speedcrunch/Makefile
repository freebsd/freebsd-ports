# New ports collection makefile for:	speedcrunch
# Date created:		27 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	speedcrunch
DISTVERSION=	0.10.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A desktop calculator for power users

USE_QT4=	qmake_build moc_build rcc_build uic_build gui xml
USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	src

MAKE_JOBS_SAFE=	yes

LRELEASE_CMD=	${LOCALBASE}/bin/lrelease-qt4
LRELEASE_ARGS=	-compress -silent

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/src/i18n && ${LRELEASE_CMD} ${LRELEASE_ARGS} *.ts
.else
	${REINPLACE_CMD} -e '/speedcrunch_TRANSLATIONS/d' ${WRKSRC}/src/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/src/gui/mainwindow.cpp

.include <bsd.port.mk>
