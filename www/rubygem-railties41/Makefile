# Created by: Torsten Zuhlsdorff
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	4.1.14
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-actionpack41>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack41 \
		rubygem-activesupport41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-thor>=0.18.1:${PORTSDIR}/devel/rubygem-thor

CONFLICTS_INSTALL=	rubygem-railties-[0-9]* rubygem-railties4-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rails

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
