# New ports collection makefile for:	kbfx
# Date created:		2006-07-30
# Whom:			makc <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kbfx
PORTVERSION=	0.4.9.3.1
PORTEPOCH=	1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=kbfx

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A new K-menu for KDE

BUILD_DEPENDS=	${CMAKE}:${PORTSDIR}/devel/cmake

CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GCC=	3.4+

do-configure:
	(cd ${WRKSRC} && ${CMAKE} ${CMAKE_ARGS})

.include <bsd.port.mk>
