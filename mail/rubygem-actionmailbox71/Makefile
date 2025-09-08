PORTNAME=	actionmailbox
PORTVERSION=	7.1.5.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack71 \
		rubygem-activejob71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob71 \
		rubygem-activerecord71>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord71 \
		rubygem-activestorage71>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
