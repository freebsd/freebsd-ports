# $FreeBSD$

PORTNAME=	topcom
DISTVERSION=	0.17.8
CATEGORIES=	math
MASTER_SITES=	http://www.rambau.wm.uni-bayreuth.de/Software/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computing triangulations of point configurations and oriented matroids

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp

USES=		autoreconf gmake localbase:ldflags
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include/cdd/
LDFLAGS+=	-lgmp -lgmpxx -lcddgmp

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-extract:
	@${RM} -r ${WRKSRC}/external

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" \
		| ${XARGS} ${REINPLACE_CMD} ' \
			s|\.\./external/lib/libcddgmp\.a|${LOCALBASE}/lib/libcddgmp.so| ; \
			s|\.\./external/lib/libgmp\.a|${LOCALBASE}/lib/libgmp.so| ; \
			s|\.\./external/lib/libgmpxx\.a|${LOCALBASE}/lib/libgmpxx.so|'

.include <bsd.port.mk>
