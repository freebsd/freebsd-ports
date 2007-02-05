# New ports collection makefile for:	pkg_replace
# Date created:				16 October 2006
# Whom:					Securedog <securedog@users.sourceforge.jp>
#
# $FreeBSD$
#

PORTNAME=	pkg_replace
PORTVERSION=	0.8.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=portutil/22116

MAINTAINER=	securedog@users.sourceforge.jp
COMMENT=	A utility for upgrading installed packages

USE_BZIP2=	YES
MAKE_ARGS=	PREFIX="${PREFIX}" \
		PORTSDIR="${PORTSDIR}" PKG_DBDIR="${PKG_DBDIR}"

MAN1=		pkg_replace.1
MANCOMPRESSED=	maybe

.include <bsd.port.mk>
