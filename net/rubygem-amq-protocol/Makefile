PORTNAME=	amq-protocol
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AMQP serialization library for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:env shebangfix
USE_RUBY=	yes

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

SHEBANG_FILES=	codegen/codegen.py

.include <bsd.port.mk>
