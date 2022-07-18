PORTNAME=	actionpack
PORTVERSION=	7.0.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview70>=${PORTVERSION}:devel/rubygem-actionview70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-rack>=2.2.0,3<3,3:www/rubygem-rack \
		rubygem-rack-test>=0.6.3:www/rubygem-rack-test \
		rubygem-rails-dom-testing-rails70>=2.0<3:textproc/rubygem-rails-dom-testing-rails70 \
		rubygem-rails-html-sanitizer>=1.2.0<2:textproc/rubygem-rails-html-sanitizer

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
