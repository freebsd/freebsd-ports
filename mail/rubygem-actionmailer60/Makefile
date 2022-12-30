PORTNAME=	actionmailer
PORTVERSION=	6.0.6
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-actionview60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview60 \
		rubygem-activejob60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob60 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails60>=2.0<3:textproc/rubygem-rails-dom-testing-rails60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
