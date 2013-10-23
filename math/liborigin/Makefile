# $FreeBSD$

PORTNAME=	liborigin
PORTVERSION=	2.0.0
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Library and utility for reading OriginLab project files

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs

CONFLICTS_INSTALL=	labplot-2.*

USES=		cmake:outsource
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOXYGEN}
post-patch:
	${REINPLACE_CMD} -e '/find_package(Doxygen)/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
