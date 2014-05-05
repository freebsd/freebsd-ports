# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$
PORTNAME=	beecrypt
PORTVERSION=	4.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF
PATCHFILES=	mpntrbits.patch
PATCH_SITES=	http://sourceforge.net/p/beecrypt/patches/_discuss/thread/bff89ba1/5387/attachment/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	BeeCrypt is an open source cryptography library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-java
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
.if defined(WITH_OPENMP)
	@${ECHO_MSG} "Configuring for OpenMP support"
	@${ECHO_MSG} "Any ports depending on beecrypt must be configured for OpenMP too."

CONFIGURE_ARGS+=	--enable-openmp
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

# Configure tries to guess our CPU-features using Linux-centric logic.
# Help it here:
.for o in sse3 sse2 sse mmx
.if ${MACHINE_CPU:M$o} != ""
CPPFLAGS+=	-DOPTIMIZE_${o:tu}
.endif
.endfor

regression-test test check: build
	${MAKE} -C ${WRKSRC} check

.include <bsd.port.mk>
