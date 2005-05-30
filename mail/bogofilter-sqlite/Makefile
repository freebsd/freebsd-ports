# New ports collection makefile for:	bogofilter-sqlite
# Date created:				2005-05-24
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	matthias.andree@gmx.de

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

CONFLICTS=	bogofilter-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-tdb-[0-9]* \
		[a-z][a-z]-bogofilter-[0-9]* bogofilter-current-[0-9]*

CONFIGURE_ARGS=	--with-database=sqlite
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
