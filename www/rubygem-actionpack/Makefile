# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	3.0.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
	rubygem-activemodel>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel \
	rubygem-tzinfo>=0.3.23:${PORTSDIR}/devel/rubygem-tzinfo \
	rubygem-erubis>=2.6.6:${PORTSDIR}/www/rubygem-erubis \
	rubygem-rack-mount>=0.6.13:${PORTSDIR}/www/rubygem-rack-mount \
	rubygem-rack-test>=0.5.7:${PORTSDIR}/www/rubygem-rack-test \
	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
	rubygem-i18n>=0.4:${PORTSDIR}/devel/rubygem-i18n

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
