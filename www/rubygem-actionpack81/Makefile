PORTNAME=	actionpack
PORTVERSION=	8.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/actionpack \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview81 \
		rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-rack-session>=1.0.1:www/rubygem-rack-session \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails81>=2.2<3:textproc/rubygem-rails-dom-testing-rails81 \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer \
		rubygem-useragent>=0.16<1:devel/rubygem-useragent

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
