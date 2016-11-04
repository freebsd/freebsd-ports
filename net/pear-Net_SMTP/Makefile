# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Net_SMTP
PORTVERSION=	1.7.2
CATEGORIES=	net mail www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class that provides an implementation of the SMTP protocol

LICENSE=	PHP301

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket

NO_ARCH=	yes
USES=		pear

OPTIONS_DEFINE=	PEAR_AUTH_SASL
PEAR_AUTH_SASL_DESC=	PEAR::Auth_SASL support

PEAR_AUTH_SASL_BUILD_DEPENDS=	${PEARDIR}/Auth/SASL.php:security/pear-Auth_SASL

.include <bsd.port.mk>
