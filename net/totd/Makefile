# New ports collection makefile for:   totd
# Date created:        17 Nov 2000
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	kris@FreeBSD.org

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
