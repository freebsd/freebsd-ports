# New ports collection makefile for:	adasockets
# Date created:		22 May 2000
# Whom:			sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	adasockets
PORTVERSION=	1.8.4
CATEGORIES=	net
MASTER_SITES=	http://www.rfc1149.net/download/adasockets/

MAINTAINER=	sam@rfc1149.net
COMMENT=	Sockets library for Ada

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat \
		texi2dvi:${PORTSDIR}/print/teTeX

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		adasockets-config.1
INFO=		adasockets

.include <bsd.port.mk>
