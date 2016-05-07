# $FreeBSD$

PORTNAME=	logstash-forwarder
PORTVERSION=	0.4.0.20150507
CATEGORIES=	sysutils

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Collect logs locally in preparation for processing elsewhere!

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_TAGNAME=	3b718f0

USE_RC_SUBR=	logstash-forwarder
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/logstash-forwarder.conf.example ${STAGEDIR}${PREFIX}/etc/logstash-forwarder.conf.example

.include <bsd.port.mk>
