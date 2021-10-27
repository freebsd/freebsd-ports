# Created by: Eric Freeman <freebsdports@chillibear.com>

PORTNAME=	sanitize
PORTVERSION=	5.2.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Whitelist based HTML sanitizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-crass>=1.0.2<1.1:www/rubygem-crass \
		rubygem-nokogiri>=1.8.0:textproc/rubygem-nokogiri \
		rubygem-nokogumbo>=2.0<3:textproc/rubygem-nokogumbo

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
