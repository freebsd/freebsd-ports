# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	silktools
PORTVERSION=	3.9.0
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for large-scale network capture analysis

LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libfixbuf.so:${PORTSDIR}/net/libfixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE} --enable-packing-tools --with-python
USE_LDCONFIG=	yes
USES=		gmake perl5 pkgconfig python libtool
USE_PERL5=	build
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LOCALTIME
LOCALTIME_DESC=	Use localtime instead of UTC

LOCALTIME_CONFIGURE_ON=--enable-localtime

.include <bsd.port.mk>
