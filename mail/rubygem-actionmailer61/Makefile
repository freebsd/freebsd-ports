PORTNAME=	actionmailer
PORTVERSION=	6.1.7.8
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby
WWW=		https://github.com/rails/rails/tree/main/actionmailer \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack61 \
		rubygem-actionview61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview61 \
		rubygem-activejob61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-mail>=2.5.4,2<3,2:mail/rubygem-mail \
		rubygem-rails-dom-testing-rails61>=2.0<3:textproc/rubygem-rails-dom-testing-rails61

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
