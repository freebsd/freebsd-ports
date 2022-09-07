PORTNAME=	bootstrap-sass
PORTVERSION=	3.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Bootstrap by Twitter
WWW=		https://github.com/twbs/bootstrap-sass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-autoprefixer-rails>=5.2.1:textproc/rubygem-autoprefixer-rails \
		rubygem-sassc>=2.0.0:textproc/rubygem-sassc

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	test/node_sass_compile_test.sh

.include <bsd.port.mk>
