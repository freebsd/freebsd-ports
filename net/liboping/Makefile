# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	liboping
PORTVERSION=	0.3.5
CATEGORIES=	net
MASTER_SITES=	http://verplant.org/liboping/files/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	C library to generate ICMP echo requests

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		liboping.3 ping_construct.3 ping_setopt.3 ping_host_add.3 \
		ping_send.3 ping_get_error.3 ping_iterator_get.3 \
		ping_iterator_get_info.3 ping_iterator_get_context.3
MAN8=		oping.8

NO_STAGE=	yes
.include <bsd.port.mk>
