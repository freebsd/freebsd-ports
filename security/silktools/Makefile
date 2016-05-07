# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	silktools
PORTVERSION=	3.11.0.1
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	torres.73a@gmail.com
COMMENT=	Tools for large-scale network capture analysis

LICENSE=	GPLR GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_GPLR=	Government Purpose License Rights
LICENSE_FILE_GPLR=	${WRKSRC}/doc/LICENSE.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/GPL.txt
LICENSE_PERMS_GPLR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libfixbuf.so:net/libfixbuf
BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE} --enable-packing-tools
USE_LDCONFIG=	yes
USES=		gmake perl5 pkgconfig libtool
USE_PERL5=	build
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	IPV6 LOCALTIME PYTHON STATIC
OPTIONS_DEFAULT=	PYTHON STATIC
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6
IPV6_DESC=	Support for analysis of flow records containing IPv6 addresses
LOCALTIME_DESC=	Use localtime instead of UTC
LOCALTIME_CONFIGURE_ENABLE=	localtime
PYTHON_CONFIGURE_WITH=	python
PYTHON_USES=	python
STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.mk>
