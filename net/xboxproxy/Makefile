# New ports collection makefile for:	xboxproxy
# Date created:		6 October 2005
# Whom:			Antony Mawer <ports@mawer.org>
#
# $FreeBSD$

PORTNAME=	xboxproxy
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.csh.rit.edu/~psionic/projects/xboxproxy/
DISTNAME=	proxy-${PORTVERSION}

MAINTAINER=	ports@mawer.org
COMMENT=	A proxy for the XBox system link protocol

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=xbox

PLIST_FILES=	bin/xboxproxy

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|g; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
