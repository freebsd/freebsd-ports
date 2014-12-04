# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rbvmomi
PORTVERSION=	1.8.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the VMware vSphere API

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=0:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-nokogiri>=1.4.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-trollop>=0:${PORTSDIR}/devel/rubygem-trollop \

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rbvmomish

.include <bsd.port.mk>
