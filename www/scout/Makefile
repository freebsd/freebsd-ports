# New ports collection makefile for:	scout
# Date created:			15/04/2002
# Whom:				Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	scout
PORTVERSION=	0.86
CATEGORIES=	www
MASTER_SITES=	ftp://sid.joedog.org/pub/scout/ \
	http://www.cus.org.uk/~dom/distfiles/scout/

MAINTAINER=	d.marks@student.umist.ac.uk

USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--disable-shared --enable-static
MAN1=		scout.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/scout ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/scout.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
