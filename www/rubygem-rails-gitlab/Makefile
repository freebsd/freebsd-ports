PORTNAME=	rails
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable-gitlab \
		rubygem-actionmailbox-gitlab>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox-gitlab \
		rubygem-actionmailer-gitlab>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer-gitlab \
		rubygem-actionpack-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack-gitlab \
		rubygem-actiontext-gitlab>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext-gitlab \
		rubygem-actionview-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview-gitlab \
		rubygem-activejob-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob-gitlab \
		rubygem-activemodel-gitlab>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel-gitlab \
		rubygem-activerecord-gitlab>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord-gitlab \
		rubygem-activestorage-gitlab>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties-gitlab

USES=		cpe gem

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
