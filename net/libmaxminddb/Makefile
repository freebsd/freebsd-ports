PORTNAME=	libmaxminddb
PORTVERSION=	1.11.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/maxmind/libmaxminddb/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for the MaxMind DB file format used for GeoIP2
WWW=		https://github.com/maxmind/libmaxminddb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe gmake libtool

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	maxmind

.include <bsd.port.mk>
