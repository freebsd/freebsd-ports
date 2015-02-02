# $FreeBSD$

PORTNAME=	logstash-forwarder
PORTVERSION=	0.3.1.20150121
CATEGORIES=	sysutils

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Collect logs locally in preparation for processing elsewhere!

LICENSE=	APACHE20

BUILD_DEPENDS=	go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_PROJECT=	logstash-forwarder
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9c69a36

USE_RC_SUBR=	logstash-forwarder
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/logstash-forwarder.conf.example ${STAGEDIR}${PREFIX}/etc/logstash-forwarder.conf.example

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
