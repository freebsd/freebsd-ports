PORTNAME=	hared
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small Go server for inserting notifications into MQTT
WWW=		https://github.com/jpmens/hared-hare

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	jpmens
GH_PROJECT=	hared-hare

GH_TUPLE=	go-gcfg:gcfg:438aed9:gcfg/vendor/gopkg.in/gcfg.v1 \
		go-warnings:warnings:27b9fab:warnings/vendor/gopkg.in/warnings.v0 \
		eclipse:paho.mqtt.golang:v1.5.1:paho/vendor/github.com/eclipse/paho.mqtt.golang \
		golang:sync:v0.24.0:sync/vendor/golang.org/x/sync \
		golang:net:v0.61.0:net/vendor/golang.org/x/net \
		gorilla:websocket:v1.5.3:websocket/vendor/github.com/gorilla/websocket

GO_TARGET=	./daemon:${PORTNAME}

CONFLICTS_INSTALL=	py*-${PORTNAME} # bin/hared

OPTIONS_DEFINE=	DOCS

ETCDIR=		${PREFIX}/etc

post-install:
	${INSTALL_DATA} ${WRKSRC}/daemon/hared.ini.sample ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
