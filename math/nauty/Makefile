# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	nauty
PORTVERSION=	2.6r12
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/	\
		http://pallini.di.uniroma1.it/
DISTNAME=	${PORTNAME}${PORTVERSION:S!.!!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brendan McKay's graph isomorphism tester

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PROGRAMS=	addedgeg amtog biplabg catg complg converseg copyg countg	\
		cubhamg deledgeg delptg directg dreadnaut dretodot dretog genbg	\
		genbgL geng genquarticg genrang genspecialg gentourng gentreeg	\
		hamheuristic labelg linegraphg listg multig newedgeg NRswitchg	\
		pickg planarg ranlabg shortg showg subdivideg twohamg vcolg	\
		watercluster2

PORTDOCS=	nug26.pdf
PLIST_FILES=	${PROGRAMS:S!^!bin/!}

OPTIONS_DEFINE=	DOCS

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
