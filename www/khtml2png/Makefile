# New ports collection makefile for:	www/khtml2png
# Date created:				Nov 27 2007
# Whom:                			Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	khtml2png
DISTVERSION=	2.7.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Command line program to create screenshots of webpages

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_KDELIBS_VER=	3

CMAKE?=		${LOCALBASE}/bin/cmake

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

PLIST_FILES=	bin/khtml2png2

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,QT_QT_LIBRARY,QT_LIBRARIES,g' \
		${WRKSRC}/CMakeLists.txt

do-configure:
	@cd ${WRKSRC} && ${CMAKE} ${CMAKE_ARGS} -G KDevelop3 ${WRKSRC} && \
		${CMAKE} ${CMAKE_ARGS} ${WRKSRC}

.include <bsd.port.post.mk>
