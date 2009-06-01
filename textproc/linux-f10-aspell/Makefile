# New ports collection makefile for:	textproc/linux-f10-aspell
# Date created:				2009-05-05
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.60.6
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Spelling checker with better logic than ispell (Linux Fedora 10)

CONFLICTS=	linux-aspell-[0-9]* linux-f8-aspell-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
BRANDELF_DIRS==	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
