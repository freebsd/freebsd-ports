PORTNAME=	libpaho-mqtt3
PORTVERSION=	1.3.10
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eclipse Paho C Client Library for the MQTT Protocol

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	eclipse
GH_PROJECT=	paho.mqtt.c

CMAKE_ARGS+=	-DPAHO_WITH_SSL=BOOL:TRUE

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
