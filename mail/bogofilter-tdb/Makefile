# New ports collection makefile for:	bogofilter-tdb
# Date created:				17.08.2003
# Whom:					Matthias Andree <matthias.andree@web.de>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-tdb

MASTERDIR=	${.CURDIR}/../bogofilter
LIB_DEPENDS=	tdb.1:${PORTSDIR}/databases/tdb

CONFIGURE_ARGS=	--with-tdb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
DESCR=		${PKGDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
