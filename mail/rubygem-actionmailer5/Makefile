PORTNAME=	actionmailer
PORTVERSION=	5.1.7
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack5>=${PORTVERSION}:www/rubygem-actionpack5 \
		rubygem-actionview5>=${PORTVERSION}:devel/rubygem-actionview5 \
		rubygem-activejob5>=${PORTVERSION}:devel/rubygem-activejob5 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails5>=2.0<3:textproc/rubygem-rails-dom-testing-rails5

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.1\.

.include <bsd.port.mk>
