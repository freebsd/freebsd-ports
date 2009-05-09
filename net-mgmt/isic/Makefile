# New ports collection makefile for:   isic
# Date created:                25 February 2000
# Whom:                        Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	isic
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	IP Stack Integrity Checker

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	isic.1

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
