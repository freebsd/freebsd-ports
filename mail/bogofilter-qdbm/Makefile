# New ports collection makefile for:	bogofilter-qdbm
# Date created:				2004-01-02
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-qdbm

MAINTAINER=	matthias.andree@gmx.de

LIB_DEPENDS=	qdbm.14:${PORTSDIR}/databases/qdbm

CONFLICTS=	bogofilter-[0-9]* [a-z][a-z]-bogofilter-[0-9]* bogofilter-sqlite-[0-9]* bogofilter-tc-[0-9]*

CONFIGURE_ARGS=	--with-database=qdbm
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

PLIST_FILES=	bin/bogoQDBMupgrade

MASTERDIR=	${.CURDIR}/../bogofilter

DEPRECATED=	Migrate to bogofilter-tc instead
EXPIRATION_DATE=2009-06-30

.include "${MASTERDIR}/Makefile"
