# New ports collection makefile for:	driftnet
# Date created:		28 February 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	driftnet
PORTVERSION=	0.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/ \
		http://www.vanheusden.com/mirrors/

MAINTAINER=	corecode@corecode.ath.cx

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GTK=	yes
USE_X_PREFIX=	yes
MAKEFILE=	${FILESDIR}/Makefile

.include <bsd.port.mk>
