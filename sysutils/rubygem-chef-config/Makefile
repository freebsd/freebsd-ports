# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD: head/sysutils/rubygem-chef-config/Makefile 561005 2021-01-10 08:25:32Z sunpoet $

PORTNAME=	chef-config
PORTVERSION=	16.11.7
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Default configuration and config loading library for Chef

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-chef-utils>=${PORTVERSION}:sysutils/rubygem-chef-utils \
		rubygem-fuzzyurl>=0:www/rubygem-fuzzyurl \
		rubygem-mixlib-config>=2.2.12<4.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-tomlrb1>=1.2<2:textproc/rubygem-tomlrb1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
