# New ports collection makefile for:	Palm OS PRC-Tools (gcc part)
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prc-tools-gcc
PORTVERSION=	2.0
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GCC:S/$/:gcc/} \
		${MASTER_SITE_SOURCEWARE:S/$/:gdb/}
MASTER_SITE_SUBDIR=	prc-tools releases/gcc-2.95.2/:gcc gdb/old-releases/:gdb
DISTNAME=	prc-tools-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		gcc-core-2.95.2.tar.bz2:gcc gcc-g++-2.95.2.tar.bz2:gcc \
		gdb-4.18.tar.bz2:gdb
EXTRACT_ONLY=	gdb-4.18.tar.bz2 gcc-core-2.95.2.tar.bz2 gcc-g++-2.95.2.tar.bz2

MAINTAINER=	linimon@lonesome.com

BUILD_DEPENDS=	${PREFIX}/bin/m68k-palmos-as:${PORTSDIR}/palm/prc-tools-binutils \
		${LOCALBASE}/bin/autoheader:${PORTSDIR}/devel/autoconf

USE_BZIP2=	YES
USE_BISON=	YES
USE_GMAKE=	YES
PREFIX=		${LOCALBASE}/pilot
WRKSRC=		${WRKDIR}/build
ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../prc-tools-2.0/configure
CONFIGURE_ARGS=	--target=m68k-palmos --enable-languages=c,c++ \
		--sharedstatedir=${LOCALBASE}/palmdev --prefix=${PREFIX}
CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/bin
MAKE_ENV=	PATH=${PATH}:${PREFIX}/bin
MAN1=		cccp.1 m68k-palmos-g++.1 m68k-palmos-gcc.1

.include <bsd.port.pre.mk>

CFLAGS:=	${CFLAGS:C/-m[-=0-9a-z]*//g}

post-extract:
	@(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS})

pre-patch:
	${MKDIR} ${WRKSRC}/empty
	(cd ${WRKDIR} && \
	 ${CAT} prc-tools-2.0/gcc-2.95.2.palmos.diff \
		prc-tools-2.0/gdb-4.18.palmos.diff | ${PATCH} -p0)

pre-configure:
	(cd ${WRKDIR}/prc-tools-2.0 && \
	 ${LN} -sf ../gdb-4.18 gdb; \
	 ${LN} -sf ../gcc-2.95.2 gcc)

.include <bsd.port.post.mk>
