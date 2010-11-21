# New ports collection makefile for:	qgoogletranslator
# Date created:		2010-11-20
# Whom:			Oleg Ginzburg <olevole@olevole.ru>
#
# $FreeBSD$
#

PORTNAME=	qgoogletranslator
PORTVERSION=	1.2.1
CATEGORIES=	textproc
MASTER_SITES=	http://qgt.googlecode.com/files/
DISTNAME=	qgoogletranslator-${PORTVERSION}

MAINTAINER=	olevole@olevole.ru
COMMENT=	Qt gui for google translate based on ajax api

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_BZIP2=	yes
USE_QT_VER=	4
USE_CMAKE=	yes

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include"

QT_COMPONENTS=	corelib gui network linguist_build qmake_build \
		moc_build uic_build rcc_build

LICENSE=	GPLv3

MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="QGoogleTranslator" \
		"Qt gui for google translate based on ajax api" \
		"qgoogletranslator.png" \
		"qgoogletranslator" \
		"Application;Office;" \
		"false"

post-patch:
	@${ECHO} "include_directories(${LOCALBASE}/include)" >> \
		${WRKSRC}/src/3rdparty/qxtshortcut/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/defines.h.in

.include <bsd.port.mk>
