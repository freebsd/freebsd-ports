# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsync
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=v
CATEGORIES=	net devel
PKGNAMESUFFIX=	2

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Library for delta compression of streams

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

CONFLICTS=	librsync-[0-9]* librsync1-[0-9]*

USE_GITHUB=	yes

USES=		cmake
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librsync.so.${PORTVERSION}
	${INSTALL_MAN} ${WRKSRC}/doc/librsync.3 ${STAGEDIR}${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/rdiff.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
