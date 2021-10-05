# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	actionmailbox
PORTVERSION=	6.1.3.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-activejob613>=${PORTVERSION}:devel/rubygem-activejob613 \
		rubygem-activerecord613>=${PORTVERSION}:databases/rubygem-activerecord613 \
		rubygem-activestorage613>=${PORTVERSION}:net/rubygem-activestorage613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
