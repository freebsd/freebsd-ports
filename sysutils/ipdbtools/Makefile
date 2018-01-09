# $FreeBSD$

PORTNAME=	ipdbtools
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://cyclaero.com/public/ipdbtools/

MAINTAINER=	cyclaero@gmail.com
COMMENT=	Tools for IP based Geo-blocking and Geo-routing

LICENSE=	BSD2CLAUSE

BROKEN_aarch64=		fails to compile: error: invalid conversion between vector type and integer type
BROKEN_armv6=		fails to compile: error: invalid conversion between vector type and integer type
BROKEN_armv7=		fails to compile: error: invalid conversion between vector type and integer type

USES=		tar:bzip2 compiler:c11

CFLAGS_amd64=	-mssse3

PLIST_FILES=	bin/ipup \
		bin/ipdb \
		bin/ipdb-update.sh \
		man/man1/ipdbtools.1.gz \
		man/man1/ipup.1.gz \
		man/man1/ipdb.1.gz \
		man/man1/ipdb-update.sh.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-g0 -Ofast -mssse3|${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/tmmintrin\.h/d' ${WRKSRC}/store.c

.include <bsd.port.mk>
