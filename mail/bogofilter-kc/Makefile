PORTNAME=	bogofilter
PORTREVISION=	5
CATEGORIES=	mail
PKGNAMESUFFIX=	-kc

MAINTAINER=	mandree@FreeBSD.org

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

CONFLICTS_INSTALL=	bogofilter bogofilter-lmdb bogofilter-sqlite

CONFIGURE_ARGS=	--with-database=kyotocabinet
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter-bdb

.include "${MASTERDIR}/Makefile"
