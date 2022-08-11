PORTNAME=	tailwindcss-rails
PORTVERSION=	1.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate Tailwind CSS with the asset pipeline in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties70>=6.0.0:www/rubygem-railties70

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# tailwindcss-rails 2.x uses pre-built Tailwind CSS CLI
PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
