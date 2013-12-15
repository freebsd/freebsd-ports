# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_scgi
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	dryice@dryice.name
COMMENT=	Apache 2.2 module that implements the client side of the SCGI protocol

SCGI_DIR=	apache2
WRKSRC=		${WRKDIR}/${DISTNAME}/${SCGI_DIR}

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
