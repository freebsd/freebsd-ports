# New ports collection makefile for:	lxnb
# Version required:	0.4
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	linux-netbus-client-v0.4
PKGNAME=	lxnb-0.4
CATEGORIES=	security
MASTER_SITES=	http://ns2.crw.se/~tm/projects/lxnb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}

pre-build:
	rm -f ${WRKSRC}/lxnetbus

.include <bsd.port.mk>
