# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Net_SMTP
PORTVERSION=	1.6.2
CATEGORIES=	net mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the SMTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS:=	${BUILD_DEPENDS}

LATEST_LINK=	pear-Net_SMTP
OPTIONS_DEFINE=	PEAR_AUTH_SASL
PEAR_AUTH_SASL_DESC=	PEAR::Auth_SASL support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_AUTH_SASL}
BUILD_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
