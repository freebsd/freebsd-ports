# New ports collection makefile for:	bogofilter-tdb
# Date created:				17.08.2003
# Whom:					Matthias Andree <matthias.andree@web.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
CATEGORIES=	mail
PKGNAMESUFFIX=	-tdb

MAINTAINER=	matthias.andree@gmx.de

LIB_DEPENDS=	tdb.1:${PORTSDIR}/databases/tdb

CONFLICTS=	bogofilter-[0-9]* bogofilter-qdbm-[0-9]* [a-z][a-z]-bogofilter-[0-9]* bogofilter-sqlite-[0-9]*

DEPRECATED=	TDB is inefficient and unmaintained - use -qdbm or -sqlite
EXPIRES=	2005-11-30

CONFIGURE_ARGS=	--with-database=tdb
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
