# New ports collection makefile for:	libgmp3
# Date created:			Jan 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmp
PORTVERSION=	5.0.1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gmp
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A free library for arbitrary precision arithmetic

CONFLICTS=	libgmp-4.*

OPTIONS=	CPU_OPTS "Enable assembly optimizations for your CPU" off

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--infodir=${PREFIX}/info \
		--mandir=${PREFIX}/man \
		--enable-cxx
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

INFO=		gmp

.include <bsd.port.pre.mk>

.if !defined(WITH_CPU_OPTS)
CONFIGURE_ARGS+=--build=${ARCH}-portbld-freebsd${OSREL}
.elif ${ARCH:S/64//} != ${ARCH}
CONFIGURE_ENV+=	ABI="64"
.else
CONFIGURE_ENV+=	ABI="32"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/gmp.info*

post-patch:
	${REINPLACE_CMD} "s/\(athlon64\-\*\-\*\)/amd64-*-* | \1/;s/\(x86_64)\)/amd64 | \1/" \
		${WRKSRC}/configure

regression-test check: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
