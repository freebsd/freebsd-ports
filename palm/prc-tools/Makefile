# New ports collection makefile for:    prc-tools
# Version required:     0.5.0
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id: Makefile,v 1.10 1999/01/09 08:52:30 asami Exp $
#
# *WARNING* write access to ${PREFIX} is required DURING build because the
# make "all" target actually installs the gnu tools before building the
# pilot resources
#

DISTNAME=       prc-tools.0.5.0
PKGNAME=	prc-tools-0.5.0
CATEGORIES=     palm devel
MASTER_SITES=   ftp://ryeham.ee.ryerson.ca/pub/PalmOS/ \
		${MASTER_SITE_GNU}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		binutils-2.7.tar.gz gdb-4.16.tar.gz gcc-2.7.2.2.tar.gz

MAINTAINER=     ports@freebsd.org

# install things in ${LOCALBASE}/pilot to avoid conflicts
PREFIX=		${LOCALBASE}/pilot
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
STRIP=		build-prc \
		m68k-palmos-coff-ar \
		m68k-palmos-coff-as \
		m68k-palmos-coff-c++filt \
		m68k-palmos-coff-gasp \
		m68k-palmos-coff-gcc \
		m68k-palmos-coff-gdb \
		m68k-palmos-coff-ld \
		m68k-palmos-coff-nm \
		m68k-palmos-coff-obj-res \
		m68k-palmos-coff-objcopy \
		m68k-palmos-coff-objdump \
		m68k-palmos-coff-ranlib \
		m68k-palmos-coff-size \
		m68k-palmos-coff-strings \
		m68k-palmos-coff-strip \
		pilrc \
		txt2bitm

# check for "-m486" and bomb out if the user has it
pre-build:
		@if ${ECHO} ${CFLAGS} | ${GREP} -- "-m486" > /dev/null ; then \
			${ECHO} "ERROR: You have \"-m486\" defined some-" ; \
			${ECHO} "       where, either in /etc/make.conf" ; \
			${ECHO} "       or in the CFLAGS environment" ; \
			${ECHO} "       variable.  This will cause this" ; \
			${ECHO} "       port to not build properly.  Please" ; \
			${ECHO} "       fix this and re-run make." ; \
			exit 1 ; \
		else \
			${ECHO} "Your environment looks OK." ; \
		fi

# after we apply freebsd patches, apply prc-tool's patches to gcc/gdb/...
post-patch:
		(cd ${WRKSRC} ; make patch)
		${PERL} -i -pe "s|%%PERL5%%|${PERL}|" ${WRKSRC}/stubgen

# the info files are redundant
post-install:
		${RM} -rf ${PREFIX}/info
		(cd ${PREFIX}/bin; strip ${STRIP})

.include <bsd.port.mk>
