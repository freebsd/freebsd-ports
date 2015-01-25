# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	0.0.0.20140916
CATEGORIES=	net
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Go library for AMQP client with RabbitMQ extensions

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	streadway
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7d6d180

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
