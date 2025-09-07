PORTNAME=	actionmailer
PORTVERSION=	7.2.2.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compose, deliver, and test emails on Rails
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack72 \
		rubygem-actionview72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview72 \
		rubygem-activejob72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob72 \
		rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72 \
		rubygem-mail>=2.8.0,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails72>=2.2<3:textproc/rubygem-rails-dom-testing-rails72

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>
