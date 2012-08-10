# Ports collection makefile for:	rubygem-railties
# Date created:				1 September 2010
# Whom:						Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	3.2.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-thor>=0.14.6:${PORTSDIR}/devel/rubygem-thor \
		rubygem-rack-ssl>=1.3.2:${PORTSDIR}/www/rubygem-rack-ssl \
		rubygem-rdoc>=3.4:${PORTSDIR}/devel/rubygem-rdoc

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
