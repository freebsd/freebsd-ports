PORTNAME=		libfds
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=		net-mgmt

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Flow Data Storage library for IPFIX messages
WWW=		https://github.com/CESNET/libfds

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	 liblz4.so:archivers/liblz4 \
		 libzstd.so:archivers/zstd

USES=		cmake gnome localbase:ldflags pkgconfig
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	CESNET

CXXFLAGS+=	-D_GNU_SOURCE

.include <bsd.port.mk>
