# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	nauty
PORTVERSION=	2.4r2
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}${PORTVERSION:S!.!!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brendan McKay's graph isomorphism tester

USES=		gmake
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PORTDOCS=	nug.pdf
PLIST_FILES=	${PROGRAMS:S!^!bin/!}

OPTIONS_DEFINE=	DOCS

PROGRAMS=	NRswitchg addedgeg amtog biplabg catg complg copyg \
		countg deledgeg directg dreadnaut dretog genbg geng \
		genrang gentourng labelg listg multig newedgeg pickg \
		planarg shortg showg

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 s|-O4 -march=i686|$${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
.for i in ${PROGRAMS}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
