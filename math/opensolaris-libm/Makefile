# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensolaris-libm
PORTVERSION=	2006.01.31
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C99 Math and vector libraries from OpenSolaris snv_33

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/usr/src/OPENSOLARIS.LICENSE

ONLY_FOR_ARCHS=	amd64	# i386 and sparc possible with much work
PORTSCOUT=	ignore:1

USE_GITHUB=	yes
GH_ACCOUNT=	jrmarino
GH_TAGNAME=	2017.01.31

BUILD_WRKSRC=	${WRKSRC}/usr/src/libm/wos64
INSTALL_WRKSRC=	${WRKSRC}/usr/src/libm/wos64
MAKEFILE=	Makefile.bsd
MAKE_ENV=	ARCH=${ARCH} USE_ASSEMBLY_VERSIONS=yes

# On FreeBSD 11+, libm will build on base clang.
# On FreeBSD 10, the base clang (v3.4) cannot even build libm without emitting
# Internal Compiler Errors, so GCC is required and does not appear as an
# option.  Similarly, the GCC option does not appear on DragonFly as the
# base compiler is already GCC.  Programs compiled with GCC that link to
# these libraries require that the libraries are compiled with GCC for
# proper functioning.

OPTIONS_DEFINE=			GCC
OPTIONS_EXCLUDE_FreeBSD_10=	GCC
OPTIONS_EXCLUDE_DragonFly=	GCC

GCC_USE=	GCC=yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
. if ${OSREL:R} < 11
USE_GCC=	yes
. endif

RUN_DEPENDS=	${LOCALBASE}/bin/addr2line:devel/binutils

post-patch:
	# The addr2line program in FreeBSD is inadequate, so pull in
	# binutils on FreeBSD
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|' \
		${WRKSRC}/usr/src/libm/src/m9x/__traceback.c
.endif

.include <bsd.port.mk>
