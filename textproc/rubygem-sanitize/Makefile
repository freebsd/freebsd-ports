# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	sanitize
PORTVERSION=	4.6.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Whitelist based HTML sanitizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-crass>=1.0.2<1.1:www/rubygem-crass \
		rubygem-nokogiri>=1.4.4:textproc/rubygem-nokogiri \
		rubygem-nokogumbo>=1.4<2:textproc/rubygem-nokogumbo

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
