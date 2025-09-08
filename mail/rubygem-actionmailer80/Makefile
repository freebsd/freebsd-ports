PORTNAME=	actionmailer
PORTVERSION=	8.0.2.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compose, deliver, and test emails on Rails
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack80 \
		rubygem-actionview80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview80 \
		rubygem-activejob80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-mail>=2.8.0,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails80>=2.2<3:textproc/rubygem-rails-dom-testing-rails80

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
