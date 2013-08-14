# New ports collection makefile for:   isic
# Date created:                25 February 2000
# Whom:                        Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	isic
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ISIC%20v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP Stack Integrity Checker

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

MAN1=	isic.1

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
