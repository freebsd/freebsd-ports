# New ports collection makefile for:	grub
# Whom:					rjoseph@mammalia.org
# Date created:				24 July 2000
#
# $FreeBSD$
#

PORTNAME=	grub
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	sem@ciam.ru
COMMENT=	GRand Unified Bootloader

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-freebsd-freebsd${OSREL}
ONLY_FOR_ARCHS=	i386

MAN1=		mbchk.1
MAN8=		grub.8 grub-install.8 grub-md5-crypt.8 grub-terminfo.8
INFO=		grub multiboot

#.if defined(WITH_SPLASHIMAGE)
#PATCH_SITES=	http://people.redhat.com/~katzj/grub/patches/
#PATCHFILES=	${DISTNAME}-vga16.patch ${DISTNAME}-splashimagehelp.patch
#PATCH_DIST_STRIP= -p1
#USE_AUTOCONF=	yes
#.else
#pre-fetch:
#	@${ECHO_MSG}
#	@${ECHO_MSG} "You may build grub with splash image support by"
#	@${ECHO_MSG} "defining WITH_SPLASHIMAGE."
#	@${ECHO_MSG}
#	@sleep 2
#.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
