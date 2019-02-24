# Created by: Lorenzo Salvadore
# $FreeBSD$

PORTNAME=	gfan
DISTVERSION=	0.6.2
CATEGORIES=	math
MASTER_SITES=	http://home.math.au.dk/jensen/software/gfan/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Software for computing Groebner fans and tropical varieties

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp

USES=		compiler:c++11-lang gmake localbase

CFLAGS+=	-DGMPRATIONAL

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		's,ADDITIONALLINKOPTIONS = ,ADDITIONALLINKOPTIONS = -L${LOCALBASE}/lib ,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gfan ${STAGEDIR}${PREFIX}/bin
	cd ${STAGEDIR}${PREFIX}/bin && ./gfan installlinks

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/manual.dvi ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.eps ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && ./gfan _test

.include <bsd.port.mk>
