PORTNAME=	cucumber-gherkin
PORTVERSION=	22.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages17>=17.1.1<18:devel/rubygem-cucumber-messages17

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^22\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/gherkin*

.include <bsd.port.mk>
