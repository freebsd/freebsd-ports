PORTNAME=	cucumber-gherkin
PORTVERSION=	24.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/common/tree/main/gherkin/ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages>=19.0.0<20:devel/rubygem-cucumber-messages

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

.include <bsd.port.mk>
