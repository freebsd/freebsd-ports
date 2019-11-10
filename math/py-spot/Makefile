# $FreeBSD$

PORTNAME=	spot
DISTVERSION=	2.8.3
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for 'Spot', the library for omega automata manipulation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspot.so:math/spot

USES=		compiler:c++14-lang gmake libtool python:3.4+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --disable-static

# otherwise shared libs aren't linked to spot libs for some reason
LDFLAGS+=	-L${LOCALBASE}/lib
.for l in spot bddx spotgen spotltsmin
LDFLAGS+=	-l${l}
.endfor

post-configure:
	@${REINPLACE_CMD} ' \
		s|^BUDDY_LDFLAGS =.*|BUDDY_LDFLAGS = ${LOCALBASE}/lib/libbddx.so|; \
		s|$$(top_builddir)/spot/libspot.la|${LOCALBASE}/lib/libspot.so|; \
		s|$$(top_builddir)/spot/ltsmin/libspotltsmin.la|${LOCALBASE}/lib/libspotltsmin.so|; \
		s|$$(top_builddir)/spot/gen/libspotgen.la|${LOCALBASE}/lib/libspotgen.so|' \
		${WRKSRC}/python/Makefile

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
