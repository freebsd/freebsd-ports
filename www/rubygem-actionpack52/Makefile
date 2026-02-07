PORTNAME=	actionpack
PORTVERSION=	5.2.8.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/actionpack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview52>=${PORTVERSION}:devel/rubygem-actionview52 \
		rubygem-activesupport52>=${PORTVERSION}:devel/rubygem-activesupport52 \
		rubygem-rack22>=2.0.8,3<3,3:www/rubygem-rack22 \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails52>=2.0<3:textproc/rubygem-rails-dom-testing-rails52 \
		rubygem-rails-html-sanitizer>=1.0.2<2:textproc/rubygem-rails-html-sanitizer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
