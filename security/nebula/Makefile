PORTNAME=	nebula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2
PORTREVISION=	13
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scalable overlay networking tool
WWW=		https://github.com/slackhq/nebula

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.19.0:net \
		golang:term:v0.15.0:term \
		golang:sys:v0.15.0:sys

CPE_VENDOR=	slack
GO_MODULE=	github.com/slackhq/nebula
GO_TARGET=	./cmd/nebula ./cmd/nebula-cert
GO_BUILDFLAGS=	-ldflags "-X main.Build=${PORTVERSION}"
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	bin/nebula \
		bin/nebula-cert \
		etc/${PORTNAME}/config.yml.example

pre-patch:
.for m in net term sys
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor

post-patch:
	${REINPLACE_CMD} -e s,/etc/nebula,${PREFIX}/etc/${PORTNAME}, \
		-e /dev:/s/nebula1/tun1/ \
		${WRKSRC}/examples/config.yml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/config.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.example

.include <bsd.port.mk>
