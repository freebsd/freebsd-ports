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
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgpdump
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pgpdump
.endif

.include <bsd.port.mk>
