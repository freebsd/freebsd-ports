# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	4.1.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionview>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-actionview \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-rack15>=1.5.2:${PORTSDIR}/www/rubygem-rack15 \
		rubygem-rack-test>=0.6.2:${PORTSDIR}/www/rubygem-rack-test

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
