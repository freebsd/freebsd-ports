# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	4.2.7.1
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=${PORTVERSION}:www/rubygem-actionpack4 \
		rubygem-actionview>=${PORTVERSION}:devel/rubygem-actionview \
		rubygem-activejob>=${PORTVERSION}:devel/rubygem-activejob \
		rubygem-mail>=2.6.1:mail/rubygem-mail \
		rubygem-rails-dom-testing1>=1.0.5:textproc/rubygem-rails-dom-testing1

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
