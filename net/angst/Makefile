# ex:ts=8
# New ports collection makefile for:	angst
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	angst
PORTVERSION=	0.4b
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config

USE_REINPLACE=	yes

MAN8=	angst.8

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,^CFLAGS,#CFLAGS,g ; \
		s,libnet-config,${LIBNET_CONFIG},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
