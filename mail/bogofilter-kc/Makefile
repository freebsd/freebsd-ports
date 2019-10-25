# $FreeBSD$

PORTNAME=	bogofilter
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-kc

MAINTAINER=	mandree@FreeBSD.org

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

CONFLICTS_INSTALL=	bogofilter-[0-9]* bogofilter-lmdb-[0-9]* bogofilter-sqlite-[0-9]* bogofilter-tc-[0-9]*

CONFIGURE_ARGS=	--with-database=kyotocabinet
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
