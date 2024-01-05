PORTNAME=	metasploit-model
PORTVERSION=	5.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Metasploit Model Mixins and Validators
WWW=		https://github.com/rapid7/metasploit-model

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel70>=7.0:databases/rubygem-activemodel70 \
		rubygem-activesupport70>=7.0:devel/rubygem-activesupport70 \
		rubygem-railties70>=7.0:www/rubygem-railties70

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>
