# $FreeBSD$

PORTNAME=	libilbc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet Low Bit Rate codec (RFC3951)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake localbase pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	TimothyGu

CONFLICTS=	ilbc-r[0-9]*

post-patch:
	${RMDIR} ${WRKSRC}/abseil-cpp
	${LN} -s ${PREFIX}/include/absl ${WRKSRC}/abseil-cpp

.include <bsd.port.mk>
