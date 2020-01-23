# $FreeBSD$

PORTNAME=	norm
PORTVERSION=	1.5r6
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/norm/archive/:norm \
		https://waf.io/:waf
DISTNAME=	src-norm-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:norm \
		waf-2.0.19:waf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hd@oc.dk
COMMENT=	NACK-Oriented Reliable Multicast (NORM)

WRKSRC=		${WRKDIR}/norm-${DISTVERSION}

USES=		libtool tar:tgz waf
USE_LDCONFIG=	yes
PLIST_FILES=	include/normApi.h lib/libnorm.so lib/libnorm.so.1 \
		lib/libnorm.so.1.0.0

.include <bsd.port.pre.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
CXXFLAGS+=	-mcpu=power7
.endif

post-extract:
	${CP} ${DISTDIR}/waf-2.0.19 ${WRKSRC}/waf

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/normApi.h ${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnorm.so.1.0.0

.include <bsd.port.post.mk>
