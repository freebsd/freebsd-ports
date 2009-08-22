# New ports collection makefile for:	mcrypt
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmcrypt
PORTVERSION=	2.5.8
CATEGORIES=	security
MASTER_SITES=	SF/mcrypt/Libmcrypt/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-cipher cryptographic library (used in PHP)

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--enable-static
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

MAN3=		mcrypt.3

.include <bsd.port.mk>
