# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	3.2.21
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-rack-ssl>=1.3.2:${PORTSDIR}/www/rubygem-rack-ssl \
		rubygem-rake>=0.8.7:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rdoc3>=3.4:${PORTSDIR}/devel/rubygem-rdoc3 \
		rubygem-thor>=0.14.6:${PORTSDIR}/devel/rubygem-thor

CONFLICTS_INSTALL=	rubygem-railties4-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
