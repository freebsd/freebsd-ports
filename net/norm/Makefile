# $FreeBSD$

PORTNAME=	norm
PORTVERSION=	1.5r6
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/norm/archive/
DISTNAME=	src-norm-${DISTVERSION}

MAINTAINER=	hd@oc.dk
COMMENT=	NACK-Oriented Reliable Multicast (NORM)

WRKSRC=		${WRKDIR}/norm-${DISTVERSION}

USES=		libtool python:2.7,build tar:tgz waf
USE_LDCONFIG=	yes
PLIST_FILES=	include/normApi.h lib/libnorm.so lib/libnorm.so.1 \
		lib/libnorm.so.1.0.0

post-patch:
	@${REINPLACE_CMD} -e '92s,r.*;,{&},' \
		${WRKSRC}/protolib/include/protoSpace.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/normApi.h ${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnorm.so.1.0.0

.include <bsd.port.mk>
