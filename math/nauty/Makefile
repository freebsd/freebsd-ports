# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	nauty
PORTVERSION=	27r1
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/	\
		http://pallini.di.uniroma1.it/
DISTNAME=	${PORTNAME}${PORTVERSION:S!.!!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nauty & Traces are programs for graph automorphisms

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
MAKEFILE=	makefile
TEST_TARGET=	check

PROGRAMS=	addedgeg amtog assembleg biplabg catg complg converseg copyg	\
		countg cubhamg deledgeg delptg directg dreadnaut dretodot dretog\
		edgetransg genbg genbgL geng gengL genquarticg genrang		\
		genspecialg gentourng gentreeg hamheuristic labelg linegraphg	\
		listg multig newedgeg NRswitchg pickg planarg ranlabg shortg	\
		showg subdivideg twohamg underlyingg vcolg watercluster2

PORTDOCS=	nug27.pdf
PLIST_FILES=	include/nauty/nauty.h lib/libnauty.a ${PROGRAMS:S!^!bin/!}

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} ${WRKSRC}/*.a

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nauty
	${INSTALL_DATA} ${WRKSRC}/nauty.h ${STAGEDIR}${PREFIX}/include/nauty
	# Do not use ${INSTALL_LIB} to strip the library!
	${INSTALL_DATA} ${WRKSRC}/nauty.a ${STAGEDIR}${PREFIX}/lib/libnauty.a
.for i in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
