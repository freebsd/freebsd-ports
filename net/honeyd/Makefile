# New ports collection makefile for:	honeyd
# Date created:				16/04/2002
# Whom:				Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	honeyd
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	d.marks@student.umist.ac.uk

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pcap
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN8=		honeyd.8

# This is necessary to keep auto* from running.
pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH}

.include <bsd.port.mk>
