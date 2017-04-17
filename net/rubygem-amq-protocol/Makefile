# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amq-protocol
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AMQP serialization library for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USE_RUBY=	yes
USES=		gem

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/codegen/codegen.py

.include <bsd.port.mk>
