# $FreeBSD$

PORTNAME=	logstash-forwarder
PORTVERSION=	0.3.1.20140725
CATEGORIES=	sysutils

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Collect logs locally in preparation for processing elsewhere!

LICENSE=	APACHE20

BUILD_DEPENDS=	go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_PROJECT=	logstash-forwarder
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8bb4001

USE_RC_SUBR=	logstash-forwarder
SUB_FILES=	pkg-message

do-build:
	 cd ${WRKSRC} && ${PREFIX}/bin/go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}  ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/logstash-forwarder.conf.example ${STAGEDIR}${PREFIX}/etc/logstash-forwarder.conf.example

.include <bsd.port.mk>
