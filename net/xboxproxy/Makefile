# New ports collection makefile for:	xboxproxy
# Date created:		6 October 2005
# Whom:			Antony Mawer <ports@mawer.org>
#
# $FreeBSD$

PORTNAME=	xboxproxy
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.semicomplete.com/files/xboxproxy/
DISTNAME=	proxy-${PORTVERSION}

MAINTAINER=	ports@mawer.org
COMMENT=	A proxy for the XBox system link protocol

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

USE_RC_SUBR=	xboxproxy
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=xbox

PLIST_FILES=	bin/xboxproxy

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|g; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
