PORTNAME=	onionscan
DISTVERSIONPREFIX=	OnionScan-
DISTVERSION=	0.2
PORTREVISION=	31
CATEGORIES=	security net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Free and open source tool for investigating Onion Services
WWW=		https://onionscan.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	s-rah
GH_TUPLE=	HouzuoGuo:tiedot:3.4:tiedot/vendor/github.com/HouzuoGuo/tiedot \
		rwcarlsen:goexif:8d986c0:goexif/vendor/github.com/rwcarlsen/goexif \
		golang:crypto:0e37d00:crypto/vendor/golang.org/x/crypto \
		golang:net:26e67e7:net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:sys/vendor/golang.org/x/sys

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/onionscan

.include <bsd.port.mk>
