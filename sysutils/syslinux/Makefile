# New ports collection makefile for:	syslinux
# Date created:		Nov.15, 2008
# Whom:			luigi@FreeBSD.org
#
# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	syslinux
PORTVERSION=	4.05
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/utils/boot/syslinux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Syslinux for FreeBSD

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		syslinux.1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

.include <bsd.port.pre.mk>

# utility target to build pkg-plist
_A =	mbr/mbr.bin mbr/gptmbr.bin \
	core/pxelinux.0 core/isolinux.bin gpxe/gpxelinux.0 \
	memdisk/memdisk \
	com32/menu/*.c32 com32/modules/*.c32

# convert elf_i386 to elf_i386_fbsd
pre-patch:
	@(cd ${WRKSRC}; 						\
	${FIND} . -type f -exec ${GREP} -le 'elf_i386' \{\} \; | 	\
		${XARGS} ${REINPLACE_CMD} -e 's/elf_i386/elf_i386_fbsd/g;' )

build_pkg-plist:
	@( ${ECHO} "bin/syslinux"	;		\
	  cd ${WRKSRC}; for i in ${_A} ; do	\
		${ECHO} share/syslinux/`basename $$i` ; done ; \
	  ${ECHO} "@dirrm share/syslinux" )

do-install:
	${MKDIR} ${DATADIR}
	( cd ${WRKSRC}; ${INSTALL_DATA} ${_A} ${DATADIR} )
	${INSTALL_PROGRAM} ${WRKSRC}/mtools/syslinux ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/syslinux.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
