# New ports collection makefile for:	pgpdump
# Date created:				19 Jul 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	pgpdump
PORTVERSION=	0.04
CATEGORIES=	security
MASTER_SITES=	ftp://pgp.iijlab.net/pub/tools/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	kaoru@kaisei.org

HAS_CONFIGURE=  yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgpdump ${PREFIX}/bin

.include <bsd.port.mk>
