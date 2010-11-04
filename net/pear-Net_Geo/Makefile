# Ports collection makefile for:  pear-Net_Geo
# Date created:			  2006/12/22
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	Net_Geo
PORTVERSION=	1.0.5
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Geographical locations based on Internet address

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Cache.php:${PORTSDIR}/sysutils/pear-Cache \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Net/Geo.php README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
