# New ports collection makefile for:	scout
# Date created:			15/04/2002
# Whom:				Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	scout
PORTVERSION=	0.70
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.armstrong.com/pub/scout/ \
		http://nerf-herder.net/siege/

MAINTAINER=	dominic_marks@btinternet.com

USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--disable-shared --enable-static
MAN1=		scout.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/scout ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/scout.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
