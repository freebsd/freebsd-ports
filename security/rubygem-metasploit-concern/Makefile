# $FreeBSD$

PORTNAME=	metasploit-concern
PORTVERSION=	0.4.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatically include Modules from app/concerns

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-railties>=3.0.0:${PORTSDIR}/www/rubygem-railties

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
