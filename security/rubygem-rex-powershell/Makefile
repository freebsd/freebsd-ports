# $FreeBSD$

PORTNAME=	rex-powershell
PORTVERSION=	0.1.87
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) library for generating Powershell scripts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rex-random_identifier>=0:security/rubygem-rex-random_identifier \
		rubygem-rex-text>=0:security/rubygem-rex-text \
		rubygem-ruby-rc4>=0:security/rubygem-ruby-rc4

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
