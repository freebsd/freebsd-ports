# New ports collection makefile for:   nauty
# Date created:        May 24 2001
# Whom:                bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	nauty
PORTVERSION=	2.0b9
CATEGORIES=	math
MASTER_SITES=	http://cs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}20beta9

MAINTAINER=	bremner@unb.ca
COMMENT=	Brendan McKay's graph isomorphism tester

WRKSRC=		${WRKDIR}/${PORTNAME}20
MAKEFILE=	makefile
ALL_TARGET=	nauty
NO_INSTALL_MANPAGES=yes
USE_REINPLACE=	yes
PORTDOCS=	oldmanual.ps read.me
PLIST_FILES=	bin/dreadnaut bin/dreadnaut1 bin/dreadnautL1 bin/dreadnautB

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-O4|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	cd ${WRKSRC}; 	${INSTALL_PROGRAM} dreadnaut dreadnaut1 \
		dreadnautL1 dreadnautB  ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
