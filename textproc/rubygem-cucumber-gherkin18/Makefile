PORTNAME=	cucumber-gherkin
PORTVERSION=	18.1.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	18

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages15>=15.0.0<16:devel/rubygem-cucumber-messages15

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

PORTSCOUT=	limit:^18\.

.include <bsd.port.mk>
