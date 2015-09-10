# $FreeBSD$

PORTNAME=	metasploit-model
PORTVERSION=	0.29.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Metasploit Model Mixins and Validators

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-railties>=3.0.0:${PORTSDIR}/www/rubygem-railties

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
