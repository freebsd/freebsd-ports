# New ports collection makefile for:    prc-tools
# Version required:     0.5.0
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id$
#
# *WARNING* write access to ${PREFIX} is required DURING build because the
# make "all" target actually installs the gnu tools before building the
# pilot resources
#

DISTNAME=       prc-tools.0.5.0
PKGNAME=	prc-tools-0.5.0
CATEGORIES=     devel
MASTER_SITES=   ftp://ryeham.ee.ryerson.ca/pub/PalmOS/ \
		${MASTER_SITE_GNU}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		binutils-2.7.tar.gz gdb-4.16.tar.gz gcc-2.7.2.2.tar.gz

MAINTAINER=     ports@freebsd.org

# install things in ${LOCALBASE}/palm to avoid conflicts
PREFIX=		${LOCALBASE}/palm
WRKSRC=		${WRKDIR}/${PKGNAME}

USE_PERL5=	yes
ALL_TARGET=	gnutools all
MAN1=		build-prc.1 cccp.1 configure.1 \
		obj-res.1 pilrc.1 txt2bitm.1 \
		m68k-palmos-coff-ar.1 \
		m68k-palmos-coff-as.1 \
		m68k-palmos-coff-c++filt.1 \
		m68k-palmos-coff-gcc.1 \
		m68k-palmos-coff-gdb.1 \
		m68k-palmos-coff-ld.1 \
		m68k-palmos-coff-nlmconv.1 \
		m68k-palmos-coff-nm.1 \
		m68k-palmos-coff-objcopy.1 \
		m68k-palmos-coff-objdump.1 \
		m68k-palmos-coff-ranlib.1 \
		m68k-palmos-coff-size.1 \
		m68k-palmos-coff-strings.1 \
		m68k-palmos-coff-strip.1

# after we apply freebsd patches, apply prc-tool's patches to gcc/gdb/...
post-patch:
		(cd ${WRKSRC} ; make patch)

# the info files are redundant
post-install:
		${RM} -rf ${PREFIX}/info

.include <bsd.port.mk>
