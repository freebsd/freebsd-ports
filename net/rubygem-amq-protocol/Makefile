PORTNAME=	amq-protocol
PORTVERSION=	2.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AMQP serialization library for Ruby
WWW=		https://github.com/ruby-amqp/amq-protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:env shebangfix

NO_ARCH=	yes

PLIST_FILES=	${GEM_LIB_DIR}/CLAUDE.md \
		${GEM_LIB_DIR}/GEMINI.md

SHEBANG_FILES=	codegen/codegen.py

.include <bsd.port.mk>
