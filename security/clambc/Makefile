# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clambc
DISTVERSION=	0.98.5rc1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/clamav/${PORTNAME:tl}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bytecode signature compiler for ClamAV

LICENSE=	GPLv2

DEPRECATED=	Practically unmaintained, featuring issues elsewhere solved 6 years ago
EXPIRATION_DATE=2017-09-13

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	fails to configure: error: Can not set target to build

USES=		gmake libtool perl5
ALL_TARGET=	clambc-only
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
USE_GCC=	5	# fails to build with GCC 6+
USE_LDCONFIG=	yes
USE_PERL5=	build
CONFIGURE_SCRIPT=llvm/configure
CONFIGURE_ARGS=	--enable-optimized --enable-targets=host-only \
		--disable-bindings --enable-bindings=none

WRKSRC=		${WRKDIR}/clamav-bytecode-compiler-${DISTNAME}

MAKE_JOBS_UNSAFE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/include/
	@${RM} ${WRKSRC}/clang/lib/Headers/CMakeLists.txt \
		${WRKSRC}/clang/lib/Headers/Makefile
	(cd ${WRKSRC}/clang/lib/Headers/ && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/include/)
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/Release/bin/clambc-compiler \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
