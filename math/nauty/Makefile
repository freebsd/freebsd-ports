# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	nauty
PORTVERSION=	2.4r2
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}${PORTVERSION:S!.!!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brendan McKay's graph isomorphism tester

LICENSE=	NAUTY
LICENSE_NAME=	nauty license
LICENSE_FILE=	${WRKDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		gmake
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PROGRAMS=	NRswitchg addedgeg amtog biplabg catg complg copyg \
		countg deledgeg directg dreadnaut dretog genbg geng \
		genrang gentourng labelg listg multig newedgeg pickg \
		planarg shortg showg

PORTDOCS=	nug.pdf
PLIST_FILES=	${PROGRAMS:S!^!bin/!}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${SED} -ne '/AUTHOR/,/RIP/ {s|^\*   ||; s|  *\*$$||;p;}' \
		< ${WRKSRC}/nauty.h > ${WRKDIR}/LICENSE

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 s|-O4 -march=i686|$${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
.for i in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
