# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	ruby-saml
PORTVERSION=	1.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SAML toolkit for Ruby on Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.5.10:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-uuid>=2.3:${PORTSDIR}/devel/rubygem-uuid

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
