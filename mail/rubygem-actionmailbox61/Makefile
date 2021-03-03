# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actionmailbox
PORTVERSION=	6.1.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}:www/rubygem-actionpack61 \
		rubygem-activejob61>=${PORTVERSION}:devel/rubygem-activejob61 \
		rubygem-activerecord61>=${PORTVERSION}:databases/rubygem-activerecord61 \
		rubygem-activestorage61>=${PORTVERSION}:net/rubygem-activestorage61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
