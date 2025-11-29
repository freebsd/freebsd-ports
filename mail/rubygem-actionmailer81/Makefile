PORTNAME=	actionmailer
PORTVERSION=	8.1.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compose, deliver, and test emails on Rails
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack81 \
		rubygem-actionview81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview81 \
		rubygem-activejob81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob81 \
		rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-mail>=2.8.0,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails81>=2.2<3:textproc/rubygem-rails-dom-testing-rails81

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
