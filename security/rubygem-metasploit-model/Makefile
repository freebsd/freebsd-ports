# $FreeBSD$

PORTNAME=	metasploit-model
PORTVERSION=	0.29.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Metasploit Model Mixins and Validators

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=0:devel/rubygem-activesupport \
		rubygem-railties>=3.0.0:www/rubygem-railties

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
