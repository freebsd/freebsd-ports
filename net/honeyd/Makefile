# New ports collection makefile for:	honeyd
# Date created:				16/04/2002
# Whom:				Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	honeyd
PORTVERSION=	0.4a
CATEGORIES=	net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	d.marks@student.umist.ac.uk
COMMENT=	A utility to simualte services and hosts on a virtual network host

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pcap
MAN8=		honeyd.8

.include <bsd.port.mk>
