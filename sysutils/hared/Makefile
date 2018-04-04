# $FreeBSD$

PORTNAME=	hared
DISTVERSION=	1.0-41
DISTVERSIONSUFFIX=	-ge17cdc6
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Small Go server for inserting notifications into MQTT

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	jpmens
GH_PROJECT=	hared-hare

GH_TUPLE=	go-gcfg:gcfg:f02745a:gcfg/src/gopkg.in/gcfg.v1 \
		go-warnings:warnings:27b9fab:warnings/src/gopkg.in/warnings.v0 \
		eclipse:paho.mqtt.golang:d4f545e:paho/src/github.com/eclipse/paho.mqtt.golang \
		golang:net:9dfe398:net/src/golang.org/x/net \
		gorilla:websocket:7a8dacf:websocket/src/github.com/gorilla/websocket

OPTIONS_DEFINE=	DOCS

ETCDIR=		${PREFIX}/etc

do-build:
	(cd ${GO_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${GO_CMD} build -o ${GO_PKGNAME} ./daemon/hared.go)

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/${GO_PKGNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/daemon/hared.ini.example \
		${STAGEDIR}${ETCDIR}/hared.ini.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
