# Created by: Marcin Cieslak <saper@system.pl>
# $FreeBSD$

PORTNAME=	wackamole
PORTVERSION=	2.1.5
CATEGORIES=	net
MASTER_SITES=	https://BSDforge.com/projects/source/net/wackamole/ \
		http://mirrors.omniti.com/wackamole/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Peer-to-peer high availability cluster

LIB_DEPENDS=	libspread.so:net/spread

USES=		tar:xz
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	YACC=${YACC}

.include <bsd.port.mk>
