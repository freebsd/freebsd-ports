PORTNAME=	actionpack
PORTVERSION=	7.2.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/actionpack \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview72 \
		rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri \
		rubygem-racc>=0:devel/rubygem-racc \
		rubygem-rack>=2.2.4,3<3.2,3:www/rubygem-rack \
		rubygem-rack-session>=1.0.1:www/rubygem-rack-session \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails72>=2.2<3:textproc/rubygem-rails-dom-testing-rails72 \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer \
		rubygem-useragent>=0.16<1:devel/rubygem-useragent

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>
