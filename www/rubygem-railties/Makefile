# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	3.2.17
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-thor>=0.19.0:${PORTSDIR}/devel/rubygem-thor \
		rubygem-rack-ssl>=1.3.2:${PORTSDIR}/www/rubygem-rack-ssl

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
