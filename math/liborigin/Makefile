# $FreeBSD$

PORTNAME=	liborigin
PORTVERSION=	2.0.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library and utility for reading OriginLab project files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING # GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs

CONFLICTS_INSTALL=	labplot-2.*

USES=		cmake:outsource
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-patch-DOXYGEN-off:
	@${REINPLACE_CMD} -e '/find_package(Doxygen)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
