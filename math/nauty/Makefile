# Created by: bremner@unb.ca

PORTNAME=	nauty
PORTVERSION=	27r1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://users.cecs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	moritz@schmi.tt
COMMENT=	Nauty & Traces are programs for computing graph automorphisms

LICENSE=	APACHE20

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tls # math/libnormaliz requires nauty with tls

MAKEFILE=	makefile

TEST_TARGET=	check

CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DOCS

post-build:
	@cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnauty.so \
		gtnauty.o gtools.o gutil1.o gutil2.o naugraph.o naugroup.o naurng.o nausparse.o nautil.o nautinv.o \
		naututil.o nauty.o nautycliquer.o schreier.o traces.o

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nauty
.for h in  nauty.h nautycliquer.h nausparse.h traces.h naugroup.h
	${INSTALL_DATA} ${WRKSRC}/${h} ${STAGEDIR}${PREFIX}/include/nauty
.endfor
	# Do not use ${INSTALL_LIB} to strip the library!
	${INSTALL_DATA} ${WRKSRC}/nauty.a ${STAGEDIR}${PREFIX}/lib/libnauty.a
	${INSTALL_LIB} ${WRKSRC}/libnauty.so ${STAGEDIR}${PREFIX}/lib
.for e in \
	NRswitchg addedgeg amtog assembleg biplabg catg complg converseg copyg countg \
	cubhamg deledgeg delptg directg dreadnaut dretodot dretog edgetransg genbg genbgL \
	geng gengL genquarticg genrang genspecialg gentourng gentreeg hamheuristic labelg linegraphg \
	listg multig newedgeg pickg planarg ranlabg shortg showg subdivideg twohamg \
	underlyingg vcolg watercluster2
	${INSTALL_PROGRAM} ${WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/nug27.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
