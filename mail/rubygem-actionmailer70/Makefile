PORTNAME=	actionmailer
PORTVERSION=	7.0.8.4
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compose, deliver, and test emails on Rails
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack70 \
		rubygem-actionview70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview70 \
		rubygem-activejob70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-rails-dom-testing-rails70>=2.0<3:textproc/rubygem-rails-dom-testing-rails70

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
