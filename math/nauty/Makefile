# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	nauty
PORTVERSION=	2.4r2
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}24r2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brendan McKay's graph isomorphism tester

WRKSRC=		${WRKDIR}/${PORTNAME}24r2
MAKEFILE=	makefile
USE_CSTD=	gnu89
GNU_CONFIGURE=	YES
PORTDOCS=	nug.pdf

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-O4 -march=i686|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} dreadnaut copyg listg labelg dretog \
		amtog geng complg shortg showg NRswitchg biplabg addedgeg \
		deledgeg countg pickg genrang newedgeg catg genbg directg \
		multig planarg gentourng ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
