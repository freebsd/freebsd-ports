PORTNAME=	node
PORTVERSION=	${NODEJS_PORTVERSION}
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V8 JavaScript for client and server (meta port)
WWW=		https://nodejs.org/ \
		https://github.com/nodejs/node

USES=		metaport nodejs:run

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../node${NODEJS_VERSION}/Makefile.version"
.include <bsd.port.post.mk>
