# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	4.1.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack4>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-thor>=0.18.1:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
