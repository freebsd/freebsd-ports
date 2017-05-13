# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	5.0.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack50>=${PORTVERSION}:www/rubygem-actionpack50 \
		rubygem-actionview50>=${PORTVERSION}:devel/rubygem-actionview50 \
		rubygem-activejob50>=${PORTVERSION}:devel/rubygem-activejob50 \
		rubygem-mail>=2.5.4:mail/rubygem-mail \
		rubygem-rails-dom-testing>=2.0:textproc/rubygem-rails-dom-testing

PORTSCOUT=	limit:^5\.0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
