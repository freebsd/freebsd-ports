# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	syslinux
PORTVERSION=	6.01
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/boot/syslinux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boot loader for the Linux operating system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

USES=		perl5 gmake
USE_XZ=		yes
USE_PERL5=	build
MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	bios

#.include <bsd.port.pre.mk>

# convert elf_i386 to elf_i386_fbsd
pre-patch:
	@(cd ${WRKSRC}; 						\
	${FIND} . -type f -exec ${GREP} -le 'elf_i386' \{\} \; | 	\
		${XARGS} ${REINPLACE_CMD} -e 's/elf_i386/elf_i386_fbsd/g;' )

post-patch:
	@${REINPLACE_CMD} -e \
		's|^UMAKEDEPS|#UMAKEDEPS|' ${WRKSRC}/mk/syslinux.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bios/mtools/syslinux ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/syslinux.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${FIND} -d ${WRKSRC} -type d -empty -delete
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bios efi32 efi64" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
