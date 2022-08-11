PORTNAME=	nfstrace
PORTVERSION=	0.4.3.2
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	NFS and CIFS tracing/monitoring/capturing/analyzing tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	epam

CMAKE_ARGS+=	-DJSON_INCLUDE_DIR="${LOCALBASE}/include/json-c"
CFLAGS+=	-Wno-deprecated-copy

.include <bsd.port.mk>
