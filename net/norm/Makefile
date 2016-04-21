# $FreeBSD$

PORTNAME=	norm
PORTVERSION=	1.5r6
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/norm/archive/
DISTNAME=	src-norm-${DISTVERSION}

MAINTAINER=	hd@oc.dk
COMMENT=	NACK-Oriented Reliable Multicast (NORM)

BROKEN_powerpc64=	Does not build

WRKSRC=		${WRKDIR}/norm-${DISTVERSION}

USES=		waf tar:tgz libtool
USE_LDCONFIG=	yes
PLIST_FILES=	include/normApi.h lib/libnorm.so lib/libnorm.so.1 \
		lib/libnorm.so.1.0.0

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/normApi.h ${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnorm.so.1.0.0

.include <bsd.port.mk>
