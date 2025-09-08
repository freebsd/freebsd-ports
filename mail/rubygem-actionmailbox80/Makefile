PORTNAME=	actionmailbox
PORTVERSION=	8.0.2.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack80 \
		rubygem-activejob80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob80 \
		rubygem-activerecord80>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord80 \
		rubygem-activestorage80>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-mail>=2.8.0,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
