# New ports collection makefile for:	honeyd
# Date created:				16/04/2002
# Whom:				Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	honeyd
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	dominic.marks@btinternet.com
COMMENT=	A utility to simualte services and hosts on a virtual network host

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_TARGET= --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pcap
MAN8=		honeyd.8

.include <bsd.port.mk>
