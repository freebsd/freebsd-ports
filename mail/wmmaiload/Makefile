# New ports collection makefile for:	wmmaiload
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmmaiload
PORTVERSION=	0.6.0
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmmaiload ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/wmmaiload.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
