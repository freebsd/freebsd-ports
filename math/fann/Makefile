# New ports collection makefile for:	fann
# Date created:		2007-03-04
# Whom:			Tz-Huan Huang <tzhuan@csie.org>
#
# $FreeBSD$
#

PORTNAME=	fann
PORTVERSION=	2.2.0
CATEGORIES=	math science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	FANN-2.2.0-Source

MAINTAINER=	tzhuan@csie.org
COMMENT=	A free open source neural network library

WRKSRC=		${WRKDIR}/FANN-2.2.0-Source

USE_CMAKE=	yes
USE_ZIP=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/lib/pkgconfig|/libdata/pkgconfig|g' ${WRKSRC}/CMakeLists.txt

post-configure:
	${ENV} CPP=${CPP} CC=${CC} CXX=${CXX} ${CMAKE_BIN} ${WRKSRC} -DCMAKE_INSTALL_PREFIX=${PREFIX}

.include <bsd.port.mk>
