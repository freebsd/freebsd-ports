PORTNAME=	cucumber-gherkin
PORTVERSION=	28.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages23>=19.1.4<24:devel/rubygem-cucumber-messages23

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

.include <bsd.port.mk>
