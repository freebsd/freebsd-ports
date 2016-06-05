# Created by: bryan@freshdns.net
# $FreeBSD$

PORTNAME=	rainbowcrack
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Hash cracker that precomputes plaintext - ciphertext pairs in advance

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86 assembly

USES=		dos2unix

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's|g++|$$(CXX) $$(CXXFLAGS)|' -e 's|-O3||' \
		-e 's/-lssl/-lcrypto/' \
		${WRKSRC}/${MAKEFILE}

do-install:
.for f in rcrack rtgen rtdump rtsort
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/charset.txt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
