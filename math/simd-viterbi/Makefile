PORTNAME=	simd-viterbi
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ka9q.net/code/fec/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	Fast Viterbi CODEC library

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes
MAKEFILE=	makefile

PLIST_FILES=	include/parity.h include/viterbi27.h include/viterbi29.h \
		lib/libviterbi.a lib/libviterbi.so lib/libviterbi.so.2 \
		man/man3/simd-viterbi.3.gz
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if ${ARCH} != i386 || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-port
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/makefile.in

pre-install:
.for simd in sse2 sse mmx port
	@if [ -f ${WRKSRC}/libviterbi_${simd}.a ]; then \
		${ECHO_CMD} 'lib/libviterbi_${simd}.a' >> ${PLIST}; \
	fi
.endfor

.include <bsd.port.post.mk>
