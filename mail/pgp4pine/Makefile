# New ports collection makefile for: pgp4pine
# Date created:		29 February 2000
# Whom:			Holger Lamm <holger@flatline.de>
#
# $FreeBSD$
#

PORTNAME=	pgp4pine
PORTVERSION=	1.76
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://pgp4pine.flatline.de/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	holger@flatline.de

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAN1=		pgp4pine.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-docdir=${PREFIX}/share/doc

.include <bsd.port.mk>
