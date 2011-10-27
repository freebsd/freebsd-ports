# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	3.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activemodel>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-tzinfo>=0.3.23:${PORTSDIR}/devel/rubygem-tzinfo \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-rack>=1.3.2:${PORTSDIR}/www/rubygem-rack \
		rubygem-rack-cache>=1.0.3:${PORTSDIR}/www/rubygem-rack-cache \
		rubygem-rack-mount>=0.8.2:${PORTSDIR}/www/rubygem-rack-mount \
		rubygem-rack-test>=0.5.7:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-builder>=3.0.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-i18n>=0.6.0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-sprockets>=2.0.0:${PORTSDIR}/devel/rubygem-sprockets

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
