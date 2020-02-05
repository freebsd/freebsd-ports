# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	6.0.2.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BROKEN_RUBY24=	yes

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}:www/rubygem-actionpack60 \
		rubygem-actionview60>=${PORTVERSION}:devel/rubygem-actionview60 \
		rubygem-activejob60>=${PORTVERSION}:devel/rubygem-activejob60 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails60>=2.0<3:textproc/rubygem-rails-dom-testing-rails60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
