# New ports collection makefile for:	textproc/linux-f8-aspell
# Date created:				2008-04-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.60.5
PORTREVISION=	1
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Spelling checker with better logic than ispell (Linux Fedora 8)

CONFLICTS=	linux-aspell-[0-9]* linux-f10-aspell-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	3.fc7
BRANDELF_DIRS==	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
