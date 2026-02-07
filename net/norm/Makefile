PORTNAME=	norm
PORTVERSION=	1.5r6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/norm/archive/:norm \
		https://waf.io/:waf
DISTNAME=	src-norm-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:norm \
		waf-2.0.19:waf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/USNavalResearchLaboratory/protolib/commit/
PATCHFILES=     ba9ca1ca7d73592268ebfd5a43271303e76f461e.patch:-p1
PATCH_DIST_ARGS=	-d protolib

MAINTAINER=	hd@oc.dk
COMMENT=	NACK-Oriented Reliable Multicast (NORM)
WWW=		https://www.nrl.navy.mil/itd/ncs/products/norm

WRKSRC=		${WRKDIR}/norm-${DISTVERSION}

USES=		libtool tar:tgz waf
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
PLIST_FILES=	include/normApi.h lib/libnorm.so lib/libnorm.so.1 \
		lib/libnorm.so.1.0.0

post-extract:
	${CP} ${DISTDIR}/waf-2.0.19 ${WRKSRC}/waf

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/normApi.h ${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnorm.so.1.0.0

.include <bsd.port.mk>
