# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net_GeoIP
PORTVERSION=	1.0.0.r1
CATEGORIES=	net pear
DISTNAME=	Net_GeoIP-1.0.0RC1

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Library to perform geo-location lookups of IP addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Cache.php:${PORTSDIR}/sysutils/pear-Cache \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Cache.php:${PORTSDIR}/sysutils/pear-Cache \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
