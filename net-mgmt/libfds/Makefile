PORTNAME=		libfds
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=		net-mgmt

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Flow Data Storage library for IPFIX messages
WWW=		https://github.com/CESNET/libfds

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	 libxml2.so:textproc/libxml2 \
			 liblz4.so:archivers/liblz4 \
			 libzstd.so:archivers/zstd

USES=		cmake localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	CESNET

CXXFLAGS+=	-D_GNU_SOURCE

.include <bsd.port.mk>
