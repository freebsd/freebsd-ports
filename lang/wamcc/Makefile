# New ports collection makefile for:	wamcc
# Date created:		14 September 1999
# Whom:			Jerry Hicks <wghicks@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	wamcc
PORTVERSION=	2.23
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/contraintes/wamcc/
DISTFILES=	wamcc2.23.tar.gz prg.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prolog-to-C translator from Inria

DEPRECATED=	unmaintained, does not work with current versions of GCC, needs gcc295 which has been failing to build for months
EXPIRATION_DATE=2009-03-22

DIST_SUBDIR=	wamcc
NO_WRKSUBDIR=	yes

USE_GCC=	2.95 # compiled .pl files dump core w/ gcc 3.x

PLIST_SUB=	CC=${CC}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		does not compile on 7.X
.endif

.include <bsd.port.post.mk>
