# New ports collection makefile for:	lxnb
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lxnb
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	http://ns2.crw.se/~tm/projects/lxnb/
DISTFILES=	linux-netbus-client-v${PORTVERSION}.tgz

MAINTAINER=	kris@FreeBSD.org

pre-build:
	rm -f ${WRKSRC}/lxnetbus

.include <bsd.port.mk>
