PORTNAME=	actionpack
PORTVERSION=	6.1.7.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework
WWW=		https://github.com/rails/rails/tree/main/actionpack \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-rack22>=2.0.9,3<3,3:www/rubygem-rack22 \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails61>=2.0<3:textproc/rubygem-rails-dom-testing-rails61 \
		rubygem-rails-html-sanitizer>=1.2.0<2:textproc/rubygem-rails-html-sanitizer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
