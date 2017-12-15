# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googleauth
PORTVERSION=	0.6.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Auth Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-faraday>=0.12:www/rubygem-faraday \
		rubygem-jwt>=1.4:www/rubygem-jwt \
		rubygem-logging>=2.0:devel/rubygem-logging \
		rubygem-memoist>=0.12:devel/rubygem-memoist \
		rubygem-multi_json>=1.11:devel/rubygem-multi_json \
		rubygem-os>=0.9:devel/rubygem-os \
		rubygem-signet>=0.7:security/rubygem-signet

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
