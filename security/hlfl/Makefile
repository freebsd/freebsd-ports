# New ports collection makefile for:	hlfl
# Date Created:				8 Jun 2001
# Whom:					Arnaud S. Launay <asl@launay.org>
#
# $FreeBSD$
#

PORTNAME=	hlfl
PORTVERSION=	0.60.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.hlfl.org/pub/hlfl/

MAINTAINER=	asl@launay.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${LOCALBASE}/share/doc
DOC_FILES=	services.hlfl sample_1.hlfl sample_2.hlfl test.hlfl syntax.txt
MAN1=		hlfl.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hlfl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hlfl
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/hlfl
.endfor
.endif

.include <bsd.port.mk>
