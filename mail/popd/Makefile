# New ports collection makefile for:	popd
# Date created:				17 April 2001
# Whom:					ianf@za.uu.net
#
# $FreeBSD$
#

PORTNAME=	popd
PORTVERSION=	1.02
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp3.za.freebsd.org/pub/popd/

MAINTAINER=	ianf@za.uu.net

MAN8=   popd.8

do-build:
	cd ${WRKSRC}; make -DNOMANCOMPRESS

do-install:
	cd ${WRKSRC}; make -DNOMANCOMPRESS BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man/man install

.include <bsd.port.mk>
