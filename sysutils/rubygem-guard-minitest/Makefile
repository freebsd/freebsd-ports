# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard-minitest
PORTVERSION=	2.4.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically run your tests with Minitest framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-guard-compat>=1.2:${PORTSDIR}/sysutils/rubygem-guard-compat \
		rubygem-minitest>=3:${PORTSDIR}/devel/rubygem-minitest

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
