# $FreeBSD$

PORTNAME=	onionscan
DISTVERSIONPREFIX=	OnionScan-
DISTVERSION=	0.2
CATEGORIES=	security net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Free and open source tool for investigating Onion Services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	s-rah
GH_TUPLE=	HouzuoGuo:tiedot:3.4:tiedot/github.com/HouzuoGuo/tiedot \
		rwcarlsen:goexif:8d986c0:goexif/github.com/rwcarlsen/goexif \
		golang:crypto:0e37d00:crypto/golang.org/x/crypto \
		golang:net:26e67e7:net/golang.org/x/net \
		golang:sys:1561086:sys/golang.org/x/sys

PLIST_FILES=	bin/onionscan

do-build:
	${MKDIR} ${WRKSRC}/github.com/${GH_ACCOUNT}
	${RLN} ${WRKSRC} ${WRKSRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
	${RLN} ${WRKSRC} ${WRKSRC}/src
	cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKSRC} \
	  ${GO_CMD} build ${GO_BUILDFLAGS} -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} \
		${STAGEDIR}/${LOCALBASE}/bin

.include <bsd.port.mk>
