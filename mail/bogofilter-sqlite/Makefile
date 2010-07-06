# New ports collection makefile for:	bogofilter-sqlite
# Date created:				2005-05-24
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	mandree@FreeBSD.org

USE_SQLITE=	3

CONFLICTS=	bogofilter-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-tc-[0-9]* [a-z][a-z]-bogofilter-[0-9]*

CONFIGURE_ARGS=	--with-database=sqlite
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
