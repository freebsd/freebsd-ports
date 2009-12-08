# New ports collection makefile for:	syslinux
# Date created:		Nov.15, 2008
# Whom:			luigi@FreeBSD.org
#
# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	syslinux
PORTVERSION=	3.83
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/boot/syslinux

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	Syslinux for FreeBSD

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS= mtools:${PORTSDIR}/emulators/mtools

MAN1=		syslinux.1

USE_BZIP2=	yes
USE_GMAKE=	yes
# perl is used in post-extract to convert elf names.
USE_PERL5=	yes

.include <bsd.port.pre.mk>

# Following instructions at http://phaq.phunsites.net/2007/02/14/
#		compiling-pxelinux-and-memdisk-on-freebsd/
# convert elf_i386 to elf_i386_fbsd
post-extract:
	(cd ${WRKSRC}; 						\
	${FIND} . -type f -exec ${GREP} -le 'elf_i386' \{\} \; | 	\
		${XARGS} ${PERL} -i -p -e 's/elf_i386/elf_i386_fbsd/g;' )

# utility target to build pkg-plist
_A =	mbr/mbr.bin mbr/gptmbr.bin
_A +=	core/pxelinux.0 core/isolinux.bin gpxe/gpxelinux.0
_A +=	memdisk/memdisk
_A +=	com32/menu/*.c32 com32/modules/*.c32

build_pkg-plist:
	@( ${ECHO} "bin/syslinux"	;		\
	  cd ${WRKSRC}; for i in ${_A} ; do	\
		${ECHO} share/syslinux/`basename $$i` ; done ; \
	  ${ECHO} "@dirrm share/syslinux" )

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	( cd ${WRKSRC}; ${INSTALL_DATA} ${_A} ${PREFIX}/share/${PORTNAME} )
	${INSTALL_PROGRAM} ${WRKSRC}/mtools/syslinux ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/syslinux.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
