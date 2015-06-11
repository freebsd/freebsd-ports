# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	4.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionview>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-actionview \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-rack16>=1.6:${PORTSDIR}/www/rubygem-rack16 \
		rubygem-rack-test>=0.6.2:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-rails-html-sanitizer>=1.0:${PORTSDIR}/textproc/rubygem-rails-html-sanitizer \
		rubygem-rails-dom-testing>=2.7.0:${PORTSDIR}/textproc/rubygem-rails-dom-testing


USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
