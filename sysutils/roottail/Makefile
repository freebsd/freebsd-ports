# New ports collection makefile for:	roottail
# Date created:			30 September 1999
# Whom:				Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	roottail
PORTVERSION=	0.0.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.goof.com/pcg/marc/data/ \
		ftp://ftp.goof.com/pub/pcg/marc/
DISTNAME=	root-tail-${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

MAN1=		root-tail.1
USE_IMAKE=	yes
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/root-tail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/root-tail.man ${PREFIX}/man/man1/root-tail.1

.include <bsd.port.mk>
