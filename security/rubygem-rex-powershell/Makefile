# $FreeBSD$

PORTNAME=	rex-powershell
PORTVERSION=	0.1.71
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) library for generating Powershell scripts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rex-random_identifier>=0:security/rubygem-rex-random_identifier \
		rubygem-rex-text>=0:security/rubygem-rex-text

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
