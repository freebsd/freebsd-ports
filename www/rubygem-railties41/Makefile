# Created by: Torsten Zühlsdorff
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	4.1.13
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

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
