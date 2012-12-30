# -*-mode: makefile-*-
# New ports collection makefile for:	kdetoys3
# Date created:				14 May 2000 02:45:53
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdetoys
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES=	x11-clocks kde misc
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small applications for KDE

MAKE_JOBS_UNSAFE=	yes

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_AUTOTOOLS=  libtool
USE_GMAKE=	yes

USE_LDCONFIG=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
