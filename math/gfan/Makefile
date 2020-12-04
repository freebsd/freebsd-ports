# $FreeBSD$

PORTNAME=	gfan
DISTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://users-math.au.dk/jensen/software/gfan/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	moritz@schmi.tt
COMMENT=	Software for computing Groebner fans and tropical varieties

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp

USES=		compiler:c++11-lang gmake localbase

OPTIONS_DEFINE=	DOCS EXAMPLES

CFLAGS+=	-DGMPRATIONAL
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gfan ${STAGEDIR}${PREFIX}/bin
	cd ${STAGEDIR}${PREFIX}/bin && ./gfan installlinks

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/manual.dvi ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.eps ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && ./gfan _test

.include <bsd.port.mk>
