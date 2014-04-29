# Created by: Marcin Cieslak <saper@system.pl>
# $FreeBSD$

PORTNAME=	wackamole
PORTVERSION=	2.1.4
CATEGORIES=	net
MASTER_SITES=	http://mirrors.omniti.com/wackamole/

MAINTAINER=	saper@saper.info
COMMENT=	Peer-to-peer high availability cluster

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	YACC=${YACC}

.include <bsd.port.mk>
