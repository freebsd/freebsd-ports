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
DISTNAME=	linux-netbus-client-v0.4
EXTRACT_SUFX=	.tgz

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}

pre-build:
	rm -f ${WRKSRC}/lxnetbus

.include <bsd.port.mk>
