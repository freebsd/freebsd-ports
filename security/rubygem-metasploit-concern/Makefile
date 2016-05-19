# $FreeBSD$

PORTNAME=	metasploit-concern
PORTVERSION=	2.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatically include Modules from app/concerns

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.2.6:databases/rubygem-activemodel4 \
		rubygem-activesupport4>=4.2.6:devel/rubygem-activesupport4 \
		rubygem-railties4>=4.2.6:www/rubygem-railties4

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
