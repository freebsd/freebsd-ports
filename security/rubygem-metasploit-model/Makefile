PORTNAME=	metasploit-model
PORTVERSION=	5.0.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Metasploit Model Mixins and Validators
WWW=		https://github.com/rapid7/metasploit-model

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel71>=7.1:databases/rubygem-activemodel71 \
		rubygem-activesupport71>=7.1:devel/rubygem-activesupport71 \
		rubygem-railties71>=7.1:www/rubygem-railties71

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>
