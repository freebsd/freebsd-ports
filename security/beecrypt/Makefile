# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beecrypt
PORTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF
PATCHFILES=	mpntrbits.patch
PATCH_SITES=	http://sourceforge.net/p/beecrypt/patches/_discuss/thread/bff89ba1/5387/attachment/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	BeeCrypt is an open source cryptography library

BROKEN_powerpc64=	Does not build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-java --without-python
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENMP
OPENMP_CONFIGURE_ENABLE=	openmp

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MOPENMP}
	@${ECHO_MSG} "Configuring for OpenMP support"
	@${ECHO_MSG} "Any ports depending on beecrypt must be configured for OpenMP too."
.endif

# Configure tries to guess our CPU-features using Linux-centric logic.
# Help it here:
.for o in sse3 sse2 sse mmx
.if ${MACHINE_CPU:M$o} != ""
CPPFLAGS+=	-DOPTIMIZE_${o:tu}
.endif
.endfor

regression-test test check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
