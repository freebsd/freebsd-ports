# New ports collection makefile for:   nauty
# Date created:        May 24 2001
# Whom:                bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=      	nauty
PORTVERSION=   	2.0b9
CATEGORIES=    	math
MASTER_SITES=  	http://cs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}20beta9

MAINTAINER=    	bremner@unb.ca

WRKSRC=		${WRKDIR}/${PORTNAME}20
MAKEFILE=	makefile
ALL_TARGET=	nauty
NO_INSTALL_MANPAGES=yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/${MAKEFILE}

do-install:
	cd ${WRKSRC}; 	${INSTALL_PROGRAM} dreadnaut dreadnaut1 \
		dreadnautL1 dreadnautB  ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/oldmanual.ps ${WRKSRC}/read.me \
		${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
