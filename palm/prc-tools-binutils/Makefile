# New ports collection makefile for:	Palm OS PRC-tools (binutils part)
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prc-tools-binutils
PORTVERSION=	2.0
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	prc-tools binutils/old-releases
DISTNAME=	prc-tools-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz binutils-2.9.1.tar.bz2

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	YES
USE_BISON=	YES
USE_GMAKE=	YES
PREFIX=		${LOCALBASE}/pilot
WRKSRC=		${WRKDIR}/build
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../prc-tools-2.0/configure
CONFIGURE_ARGS=	--target=m68k-palmos --enable-languages=c,c++ \
		--sharedstatedir=${LOCALBASE}/palmdev --prefix=${PREFIX}
ALL_TARGET=	all-host
INSTALL_TARGET=	install-host
MAN1=		m68k-palmos-addr2line.1 m68k-palmos-ar.1 \
		m68k-palmos-as.1 m68k-palmos-c++filt.1 \
		m68k-palmos-ld.1 m68k-palmos-nlmconv.1 \
		m68k-palmos-nm.1 m68k-palmos-objcopy.1 \
		m68k-palmos-objdump.1 m68k-palmos-ranlib.1 \
		m68k-palmos-size.1 m68k-palmos-strings.1 \
		m68k-palmos-strip.1

post-extract:
	@(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS})

pre-patch:
	${MKDIR} ${WRKSRC}/empty
	(cd ${WRKDIR} && \
	 ${CAT} prc-tools-2.0/binutils-2.9.1.palmos.diff | ${PATCH} -p0)

pre-configure:
	(cd ${WRKDIR}/prc-tools-2.0 && \
	 ${LN} -sf ../binutils-2.9.1 binutils)

post-install:
	${RM} ${PREFIX}/bin/m68k-palmos-c++filt
	${RM} ${PREFIX}/lib/libiberty.a

.include <bsd.port.mk>
