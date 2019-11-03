# $FreeBSD$

PORTNAME=	net-ssh-gateway
PORTVERSION=	1.3.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Establish Net::SSH connections through firewalls

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ssh>=2.6.5:security/rubygem-net-ssh

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
