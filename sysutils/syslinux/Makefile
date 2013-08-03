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

USES=		perl5
USE_XZ=		yes
USE_PERL5=	build
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	bios

MAN1=		syslinux.1

PLIST_FILES+=	bin/syslinux

.include <bsd.port.pre.mk>

# convert elf_i386 to elf_i386_fbsd
pre-patch:
	@(cd ${WRKSRC}; 						\
	${FIND} . -type f -exec ${GREP} -le 'elf_i386' \{\} \; | 	\
		${XARGS} ${REINPLACE_CMD} -e 's/elf_i386/elf_i386_fbsd/g;' )

post-patch:
	@${REINPLACE_CMD} -e \
		's|^UMAKEDEPS|#UMAKEDEPS|' ${WRKSRC}/mk/syslinux.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bios/mtools/syslinux ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/syslinux.1 ${MANPREFIX}/man/man1
	@${FIND} -d ${WRKSRC} -type d -empty -delete
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bios efi32 efi64" ${DATADIR})

post-install:
	@(cd ${PREFIX} && ${FIND} -d ${DATADIR_REL} -type f >> ${TMPPLIST})
	@(cd ${PREFIX} && ${FIND} -d ${DATADIR_REL} -type d -exec echo "@dirrm {}" \; >> ${TMPPLIST})

.include <bsd.port.post.mk>
