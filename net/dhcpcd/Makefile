# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	5.5.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://roy.marples.name/downloads/dhcpcd/ \
		LOCAL/delphij

MAINTAINER=	roy@marples.name
COMMENT=	DHCP client

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	dhcpcd

CONFIGURE_ARGS+= --mandir=${PREFIX}/man

.include <bsd.port.mk>
