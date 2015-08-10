# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	devise-two-factor
PORTVERSION=	1.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT

RUN_DEPENDS?=	rubygem-activemodel4>=4.0.0:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-activesupport4>=4.0.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-attr_encrypted>=1.3.4:${PORTSDIR}/security/rubygem-attr_encrypted \
		rubygem-devise-rails4>=3.2.4:${PORTSDIR}/devel/rubygem-devise-rails4 \
		rubygem-railties4>=4.0.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-rotp<=2.0.0:${PORTSDIR}/devel/rubygem-rotp

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

.include <bsd.port.mk>
