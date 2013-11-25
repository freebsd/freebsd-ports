# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	UDDI
PORTVERSION=	0.2.4
CATEGORIES=	www pear finance

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR UDDI for PHP

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
