# $FreeBSD$

PORTNAME=	b2sum
PORTVERSION=	0.0.d${DISTVERSION}
DISTVERSION=	20150529
DISTNAME=	blake2_code_${DISTVERSION}${EXTRACT_SUFFX}
CATEGORIES=	sysutils security
MASTER_SITES=	http://blake2.net/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	fast secure hashing

USES=		zip

ONLY_FOR_ARCH=	amd64

CFLAGS+=	-I../sse
WRKSRC_SUBDIR=	b2sum
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/b2sum

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
