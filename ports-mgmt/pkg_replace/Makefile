# Created by: Securedog <securedog@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	pkg_replace
PORTVERSION=	0.8.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=portutil/22116

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for upgrading installed packages

DEPRECATED=	Abandoned upstream, does not support pkgng. Consider using ports-mgmt/portmaster, ports-mgmt/portupgrade or pkgng
EXPIRATION_DATE=	2013-12-31

USE_BZIP2=	YES
MAKE_ARGS=	PREFIX="${PREFIX}" \
		PORTSDIR="${PORTSDIR}" PKG_DBDIR="${PKG_DBDIR}"

MAN1=		pkg_replace.1
MANCOMPRESSED=	maybe

.include <bsd.port.mk>
