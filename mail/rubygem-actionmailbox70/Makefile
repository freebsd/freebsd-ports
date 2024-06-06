PORTNAME=	actionmailbox
PORTVERSION=	7.0.8.4
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack70 \
		rubygem-activejob70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob70 \
		rubygem-activerecord70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
