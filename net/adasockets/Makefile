# New ports collection makefile for:	adasockets
# Date created:		22 May 2000
# Whom:			sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	adasockets
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	http://www.rfc1149.net/download/adasockets/

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat \
		texi2dvi:${PORTSDIR}/print/teTeX

USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

MAN1=		adasockets-config.1

.include <bsd.port.mk>
