PORTNAME=	actionmailbox
PORTVERSION=	7.2.2.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack72 \
		rubygem-activejob72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob72 \
		rubygem-activerecord72>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord72 \
		rubygem-activestorage72>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage72 \
		rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72 \
		rubygem-mail>=2.8.0,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>
