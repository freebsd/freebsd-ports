# New ports collection makefile for:	nail
# Date created:		20 October 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nail
PORTVERSION=	9.31
CATEGORIES=	mail
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/nail/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rcfile="${PREFIX}/etc/nail.rc"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-liconv"

MAN1=		nail.1

.include <bsd.port.mk>
