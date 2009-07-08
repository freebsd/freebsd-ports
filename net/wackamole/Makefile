# New ports collection makefile for:	wackamole
# Date created:		2007-05-02
# Whom:			Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	wackamole
PORTVERSION=	2.1.4
CATEGORIES=	net
MASTER_SITES=	http://mirrors.omniti.com/wackamole/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peer-to-peer high availability cluster

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	YACC=${YACC}

MAN5=		wackamole.conf.5
MAN8=		wackamole.8 wackatrl.8

.include <bsd.port.mk>
