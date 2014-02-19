# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	silktools
PORTVERSION=	3.8.1
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for large-scale network capture analysis

LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo3 \
		libfixbuf.so:${PORTSDIR}/net/libfixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE} --enable-packing-tools --with-python \
				--prefix=${STAGEDIR}/${PREFIX}
USE_PYTHON=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" GCC_FLAGS="" CFLAGS_RELEASE=""
USE_LDCONFIG=	yes
USES=		perl5
USE_PERL5=	build

OPTIONS_DEFINE=	LOCALTIME
LOCALTIME_DESC=	Use localtime instead of UTC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOCALTIME}
CONFIGURE_ARGS+=--enable-localtime
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
