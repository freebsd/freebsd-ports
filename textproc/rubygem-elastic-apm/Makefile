PORTNAME=	elastic-apm
PORTVERSION=	4.7.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Elastic APM agent for Ruby
WWW=		https://github.com/elastic/apm-agent-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-http>=3.0:www/rubygem-http \
		rubygem-ruby2_keywords>=0:devel/rubygem-ruby2_keywords

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/*

.include <bsd.port.mk>
