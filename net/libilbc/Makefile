PORTNAME=	libilbc
DISTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://github.com/TimothyGu/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Internet Low Bit Rate codec (RFC3951)
WWW=		https://github.com/TimothyGu/libilbc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake localbase pathfix
USE_LDCONFIG=	yes

CONFLICTS=	ilbc-r[0-9]*

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/abseil-cpp \
			--no-same-owner --no-same-permissions

post-patch:
	${LN} -s ${PREFIX}/include/absl ${WRKSRC}/abseil-cpp

.include <bsd.port.mk>
