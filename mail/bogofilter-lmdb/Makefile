PORTNAME=	bogofilter
PORTREVISION=	3
CATEGORIES=	mail
PKGNAMESUFFIX=	-lmdb

MAINTAINER=	mandree@FreeBSD.org

LIB_DEPENDS=	liblmdb.so:databases/lmdb

CONFLICTS_INSTALL=	bogofilter bogofilter-kc bogofilter-sqlite

CONFIGURE_ARGS=	--with-database=lmdb
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
