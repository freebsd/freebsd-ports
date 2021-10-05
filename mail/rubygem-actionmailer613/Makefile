# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	actionmailer
PORTVERSION=	6.1.3.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-actionview613>=${PORTVERSION}:devel/rubygem-actionview613 \
		rubygem-activejob613>=${PORTVERSION}:devel/rubygem-activejob613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails61>=2.0<3:textproc/rubygem-rails-dom-testing-rails61

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
