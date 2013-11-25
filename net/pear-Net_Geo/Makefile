# Created by: chinsan
# $FreeBSD$

PORTNAME=	Net_Geo
PORTVERSION=	1.0.5
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Geographical locations based on Internet address

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
