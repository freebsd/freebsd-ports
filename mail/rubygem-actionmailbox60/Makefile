PORTNAME=	actionmailbox
PORTVERSION=	6.0.6
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-activejob60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob60 \
		rubygem-activerecord60>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord60 \
		rubygem-activestorage60>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage60 \
		rubygem-activesupport60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport60 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
