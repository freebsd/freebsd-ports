# New ports collection makefile for:   rainbowcrack
# Date created:        8 May 2006
# Whom:                bryan@freshdns.net
#
# $FreeBSD$
#

PORTNAME=	rainbowcrack
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://freshdns.net/rainbowcrack/

MAINTAINER=	bryan@freshdns.net
COMMENT=	Hash cracker that precomputes plaintext - ciphertext pairs in advance

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|g++|$$(CXX) $$(CXXFLAGS)|; s|\-O3||' \
		${WRKSRC}/${MAKEFILE}

do-install:
.for f in rcrack rtgen rtdump rtsort
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/charset.txt ${EXAMPLESDIR}

.include <bsd.port.post.mk>
