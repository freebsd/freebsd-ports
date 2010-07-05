# New ports collection makefile for:	grub
# Whom:					sem@FreeBSD.org
# Date created:				10 June 2010
#
# $FreeBSD$
#

PORTNAME=	grub2
PORTVERSION=	1.98
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Multiboot boot loader

CONFLICTS=	grub-0*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BISON=		build
USE_GETTEXT=		yes
ONLY_FOR_ARCHS=		i386 amd64

INFO=		grub

OPTIONS=	MKFONT "Build grub-mkfont (require freetype2)" off

.include <bsd.port.pre.mk>

.if defined(WITH_MKFONT)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.else
MKFONT=		"@comment "
.endif

PLIST_SUB+=	MKFONT=${MKFONT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
