# New ports collection makefile for:	simd-viterbi
# Date created:		29 Jun 2005
# Whom:			Thomas Sandford <freebsduser@paradisegreen.co.uk>
#
# $FreeBSD$
#

PORTNAME=	simd-viterbi
PORTVERSION=	2.0.3
CATEGORIES=	math
MASTER_SITES=	http://www.ka9q.net/code/fec/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	A fast Viterbi CODEC library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	makefile

MAN3=		simd-viterbi.3

PLIST_FILES=	include/parity.h include/viterbi27.h include/viterbi29.h \
		lib/libviterbi.a lib/libviterbi.so lib/libviterbi.so.2.0.1
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
