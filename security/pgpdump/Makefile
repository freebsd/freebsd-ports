# New ports collection makefile for:	pgpdump
# Date created:				19 Jul 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	pgpdump
PORTVERSION=	0.22
CATEGORIES=	security
MASTER_SITES=	ftp://pgp.iijlab.net/pub/pgp/tools/	\
		ftp://ftp.mew.org/pub/pgp/tools/

MAINTAINER=	kaoru@kaisei.org
COMMENT=	PGP packet visualizer

GNU_CONFIGURE=	yes

MAN1=		pgpdump.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgpdump ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pgpdump.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
