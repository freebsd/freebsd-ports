# Created by: Brad Hendrickse <bradh@uunet.co.za>
# $FreeBSD$

PORTNAME=	isic
PORTVERSION=	0.07
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ISIC%20v${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	IP Stack Integrity Checker

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
USES=		tar:tgz

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
