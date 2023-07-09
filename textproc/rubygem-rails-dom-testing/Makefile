PORTNAME=	rails-dom-testing
PORTVERSION=	2.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyse and compare DOMs using Nokogiri
WWW=		https://github.com/rails/rails-dom-testing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=4.2.0:devel/rubygem-activesupport4 \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.0\.

.include <bsd.port.mk>
