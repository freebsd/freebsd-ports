# New ports collection makefile for:	qzeitgeist
# Date Created:				20 April 2011
# Whom:					avilla@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qzeitgeist
PORTVERSION=	0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://releases.zeitgeist-project.com/${PORTNAME}/
DISTNAME=	QtZeitgeist-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt 4 wrapper library around the Zeitgeist DBus API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus qtestlib \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}-Source

post-patch:
	${REINPLACE_CMD} -e '/\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		-e 's|share/${PORTNAME}/cmake|lib/cmake/${PORTNAME}|' \
		-e "/add_subdirectory(tests)/ d" \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/QZeitgeistConfig.cmake.in

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
