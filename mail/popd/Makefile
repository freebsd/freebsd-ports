# New ports collection makefile for:	popd
# Date created:				17 April 2001
# Whom:					ianf@za.uu.net
#
# $FreeBSD$
#

PORTNAME=	popd
PORTVERSION=	2.0.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp3.za.freebsd.org/pub/popd/

MAINTAINER=	ianf@za.uu.net

MAN8=   popd.8

INSTALLS_SHLIB=	yes
NOMANCOMPRESS=	yes

post-extract:
	${MV} ${WRKSRC}/src/popd.8 ${WRKSRC}/src/popd.mdoc

.include <bsd.port.mk>
