# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bogofilter
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	mandree@FreeBSD.org

USES=		sqlite
CONFLICTS_INSTALL=	bogofilter-[0-9]* bogofilter-lmdb-[0-9]* bogofilter-kc-[0-9]* bogofilter-tc-[0-9]*

CONFIGURE_ARGS=	--with-database=sqlite
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
