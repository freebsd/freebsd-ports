# New ports collection makefile for:	bogofilter-qdbm
# Date created:				2004-01-02
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMESUFFIX=	-qdbm

MAINTAINER=	matthias.andree@gmx.de

LIB_DEPENDS=	qdbm.9:${PORTSDIR}/databases/qdbm

CONFLICTS=	bogofilter-[0-9]* bogofilter-tdb-[0-9]* [a-z][a-z]-bogofilter-[0-9]* bogofilter-sqlite-[0-9]*

CONFIGURE_ARGS=	--with-database=qdbm
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
DESCR=		${PKGDIR}/pkg-descr

PLIST_FILES=	bin/bogoQDBMupgrade

MASTERDIR=	${.CURDIR}/../bogofilter
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
