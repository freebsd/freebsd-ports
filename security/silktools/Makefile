# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	silktools
PORTVERSION=	3.13.0
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	torres.73a@gmail.com
COMMENT=	Tools for large-scale network capture analysis

LICENSE=	GPLR GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_GPLR=	Government Purpose License Rights
LICENSE_FILE_GPLR=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_GPLR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf
BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-packing-tools
USE_LDCONFIG=	yes
USES=		gmake libtool perl5 pkgconfig
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	ADNS CARES GNUTLS IPV6 LOCALTIME LZO PYTHON SNAPPY STATIC
OPTIONS_DEFAULT=	LZO PYTHON
OPTIONS_SUB=	yes

ADNS_CONFIGURE_WITH=	adns=${LOCALBASE}
ADNS_DESC=	Asynchronous DNS resolution via adns
ADNS_LIB_DEPENDS=	libadns.so:dns/adns

CARES_CONFIGURE_WITH=	c-ares=${LOCALBASE}
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares

IPV6_CONFIGURE_ENABLE=	ipv6

GNUTLS_CONFIGURE_WITH=	gnutls=${LOCALBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LOCALTIME_DESC=	Use localtime instead of UTC
LOCALTIME_CONFIGURE_ENABLE=	localtime

LZO_CONFIGURE_WITH=	lzo=${LOCALBASE}
LZO_DESC=	LZO compression support
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2

PYTHON_CONFIGURE_WITH=	python
PYTHON_USES=	python
PYTHON_USE=	python=py3kplist

SNAPPY_CONFIGURE_WITH=	snappy=${LOCALBASE}
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy

STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.mk>
