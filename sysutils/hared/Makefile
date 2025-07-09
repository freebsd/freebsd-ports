PORTNAME=	hared
DISTVERSION=	1.0-45
DISTVERSIONSUFFIX=	-g8341d8a
PORTREVISION=	28
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Small Go server for inserting notifications into MQTT
WWW=		https://github.com/jpmens/hared-hare

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	jpmens
GH_PROJECT=	hared-hare

GH_TUPLE=	go-gcfg:gcfg:f02745a:gcfg/vendor/gopkg.in/gcfg.v1 \
		go-warnings:warnings:27b9fab:warnings/vendor/gopkg.in/warnings.v0 \
		eclipse:paho.mqtt.golang:d4f545e:paho/vendor/github.com/eclipse/paho.mqtt.golang \
		golang:net:9dfe398:net/vendor/golang.org/x/net \
		gorilla:websocket:7a8dacf:websocket/vendor/github.com/gorilla/websocket

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
