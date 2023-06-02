PORTNAME=	Mail
DISTVERSION=	1.5.0
PORTEPOCH=	1
CATEGORIES=	mail www pear

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PEAR class that provides multiple interfaces for sending emails
WWW=		https://pear.php.net/package/Mail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	pear

OPTIONS_DEFINE=	PEAR_NET_SMTP
PEAR_NET_SMTP_DESC=	PEAR::Net_SMTP support

PEAR_NET_SMTP_RUN_DEPENDS=	${PEARDIR}/Net/SMTP.php:net/pear-Net_SMTP@${PHP_FLAVOR}

.include <bsd.port.mk>
