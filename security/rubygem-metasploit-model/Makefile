PORTNAME=	metasploit-model
PORTVERSION=	4.0.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Metasploit Model Mixins and Validators

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel60>=6.0:databases/rubygem-activemodel60 \
		rubygem-activesupport60>=6.0:devel/rubygem-activesupport60 \
		rubygem-railties60>=6.0:www/rubygem-railties60

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
