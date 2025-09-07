PORTNAME=	actionpack
PORTVERSION=	7.1.5.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/actionpack \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri \
		rubygem-racc>=0:devel/rubygem-racc \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-rack-session>=1.0.1:www/rubygem-rack-session \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails71>=2.2<3:textproc/rubygem-rails-dom-testing-rails71 \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
