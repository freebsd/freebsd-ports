# Created by: bryan@freshdns.net
# $FreeBSD$

PORTNAME=	rainbowcrack
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Hash cracker that precomputes plaintext - ciphertext pairs in advance

USES=		dos2unix

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		does not compile on ia64, powerpc, or sparc64
.endif

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

.include <bsd.port.post.mk>
