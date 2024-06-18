PORTNAME=	actionpack
PORTVERSION=	5.0.7.2
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/actionpack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview50>=${PORTVERSION}:devel/rubygem-actionview50 \
		rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-rack22>=2.0,3<3,3:www/rubygem-rack22 \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails50>=2.0<3:textproc/rubygem-rails-dom-testing-rails50 \
		rubygem-rails-html-sanitizer>=1.0.2<2:textproc/rubygem-rails-html-sanitizer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.0\.

.include <bsd.port.mk>
