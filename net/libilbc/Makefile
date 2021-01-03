# $FreeBSD$

PORTNAME=	libilbc
DISTVERSION=	3.0.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/TimothyGu/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	neel@neelc.org
COMMENT=	Internet Low Bit Rate codec (RFC3951)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake localbase pathfix
USE_LDCONFIG=	yes

CONFLICTS=	ilbc-r[0-9]*

post-patch:
	${RM} -rf ${WRKSRC}/abseil-cpp
	${LN} -s ${PREFIX}/include/absl ${WRKSRC}/abseil-cpp

.include <bsd.port.mk>
