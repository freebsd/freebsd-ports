PORTNAME=	actionmailbox
PORTVERSION=	6.1.7.8
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack61 \
		rubygem-activejob61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob61 \
		rubygem-activerecord61>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord61 \
		rubygem-activestorage61>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
