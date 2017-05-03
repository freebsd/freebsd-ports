# $FreeBSD$

PORTNAME=	rex-encoder
PORTVERSION=	0.1.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) library for various polymorphic encoders

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-rex-arch>=0:security/rubygem-rex-arch \
		rubygem-rex-text>=0:security/rubygem-rex-text

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
