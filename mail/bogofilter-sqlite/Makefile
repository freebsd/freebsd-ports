# Created by: Matthias Andree <mandree@FreeBSD.org>

PORTNAME=	bogofilter
PORTREVISION=	3
CATEGORIES=	mail
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	mandree@FreeBSD.org

USES=		sqlite
CONFLICTS_INSTALL=	bogofilter bogofilter-lmdb bogofilter-kc

CONFIGURE_ARGS=	--with-database=sqlite
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter-bdb

.include "${MASTERDIR}/Makefile"
