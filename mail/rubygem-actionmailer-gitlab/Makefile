PORTNAME=	actionmailer
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Compose, deliver, and test emails on Rails
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack-gitlab \
		rubygem-actionview-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview-gitlab \
		rubygem-activejob-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-rails-dom-testing-rails-gitlab>=2.2<3:textproc/rubygem-rails-dom-testing-rails-gitlab

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
