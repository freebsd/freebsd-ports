# New ports collection makefile for:   nauty
# Date created:        May 24 2001
# Whom:                bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	nauty
PORTVERSION=	2.4r2
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/ \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}24r2

MAINTAINER=	c-s@c-s.li
COMMENT=	Brendan McKay's graph isomorphism tester

WRKSRC=		${WRKDIR}/${PORTNAME}24r2
MAKEFILE=	makefile
GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES
PORTDOCS=	nug.pdf

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
