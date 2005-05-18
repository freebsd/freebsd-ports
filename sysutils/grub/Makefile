# New ports collection makefile for:	grub
# Whom:					rjoseph@mammalia.org
# Date created:				24 July 2000
#
# $FreeBSD$
#

PORTNAME=	grub
PORTVERSION=	0.97
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	GRand Unified Bootloader

USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-freebsd-freebsd${OSREL}
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
ONLY_FOR_ARCHS=		i386

GRUB_DIR=	${DATADIR:C|^${PREFIX}/||}/i386-freebsd

MAN1=		mbchk.1
MAN8=		grub.8 grub-install.8 grub-md5-crypt.8 grub-terminfo.8
INFO=		grub multiboot
PLIST_DIRS=	${GRUB_DIR} ${DATADIR:C|^${PREFIX}/||}
PLIST_FILES=	bin/mbchk sbin/grub sbin/grub-install sbin/grub-md5-crypt \
		sbin/grub-terminfo sbin/grub-set-default \
		${GRUB_DIR}/stage1 ${GRUB_DIR}/stage2

.for f in e2fs fat ffs iso9660 jfs minix reiserfs ufs2 vstafs xfs
PLIST_FILES+=	${GRUB_DIR}/${f}_stage1_5
.endfor
PLIST_FILES+=	${GRUB_DIR}/stage2_eltorito

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
