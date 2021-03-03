# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	6.1.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}:www/rubygem-actionpack61 \
		rubygem-actionview61>=${PORTVERSION}:devel/rubygem-actionview61 \
		rubygem-activejob61>=${PORTVERSION}:devel/rubygem-activejob61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails61>=2.0<3:textproc/rubygem-rails-dom-testing-rails61

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
