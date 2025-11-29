PORTNAME=	actionmailbox
PORTVERSION=	8.1.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack81 \
		rubygem-activejob81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob81 \
		rubygem-activerecord81>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord81 \
		rubygem-activestorage81>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage81 \
		rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-mail>=2.8.0,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
