# New ports collection makefile for:	libuninameslist
# Date created:				3 November 2003
# Whom:					KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	libuninameslist
PORTVERSION=	20${DIST_VER}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libuninameslist
DISTNAME=	${PORTNAME}_src-${DIST_VER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kanou@khdd.net
COMMENT=	A library of Unicode annotation data

DIST_VER=	030713
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
ALL_TARGET=	libuninameslist.la

.include <bsd.port.mk>
