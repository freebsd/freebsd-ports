# New ports collection makefile for:	nail
# Date created:		20 October 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nail
PORTVERSION=	9.29
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/nail/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-liconv"

MAN1=		nail.1

post-patch:
	@cd ${WRKSRC} && ${TOUCH} Makefile.in aclocal.m4 stamp-h.in

.include <bsd.port.mk>
