# New ports collection makefile for:	bogofilter-qdbm
# Date created:				2004-01-02
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-qdbm

MASTERDIR=	${.CURDIR}/../bogofilter

LIB_DEPENDS=	qdbm.3:${PORTSDIR}/databases/qdbm

CONFLICTS=	bogofilter-0* bogofilter-tdb* [a-z][a-z]-bogofilter-0*

CONFIGURE_ARGS=	--with-database=qdbm
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
DESCR=		${PKGDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
