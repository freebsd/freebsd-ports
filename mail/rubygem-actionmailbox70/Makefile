# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	actionmailbox
PORTVERSION=	7.0.3.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}:www/rubygem-actionpack70 \
		rubygem-activejob70>=${PORTVERSION}:devel/rubygem-activejob70 \
		rubygem-activerecord70>=${PORTVERSION}:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
