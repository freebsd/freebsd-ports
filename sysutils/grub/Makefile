# New ports collection makefile for:	grub
# Whom:					rjoseph@mammalia.org
# Date created:				24 July 2000
#
# $FreeBSD$
#

PORTNAME=	grub
PORTVERSION=	0.5.96
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	${MACHINE_ARCH}-freebsd-freebsd${OSREL}

MAN1=		mbchk.1
MAN8=		grub.8 grub-install.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
