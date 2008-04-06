# New ports collection makefile for:    fontmatrix
# Date created:         2008-01-13
# Whom:                 Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	fontmatrix
DISTVERSION=	0.4.1
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontmatrix.net/archives/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A graphical font manager

BUILD_DEPENDS=	${CMAKE}:${PORTSDIR}/devel/cmake
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_QT_VER=	4
QT_COMPONENTS=	gui svg network moc_build uic_build rcc_build qmake_build linguist_build
INSTALLS_ICONS=	yes
MAKE_ENV+=	VERBOSE=1

CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_EXE_LINKER_FLAGS=${PTHREAD_LIBS}

OPTIONS=	FONTFORGE "With FontForge editor" off

.include <bsd.port.pre.mk>

.if defined(WITH_FONTFORGE)
RUN_DEPENDS+=	${LOCALBASE}/bin/fontforge:${PORTSDIR}/print/fontforge
.endif

post-patch:
	cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e 's:/usr/bin/fontforge:${LOCALBASE}/bin/fontforge:g' \
		prefs_panel.ui \
		typotek.cpp

pre-configure:
	cd ${WRKSRC}/src/messages && \
		${LOCALBASE}/bin/lupdate-qt4 -noobsolete ../ -ts *.ts && \
		${LOCALBASE}/bin/lrelease-qt4 *.ts

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS}

.include <bsd.port.post.mk>
