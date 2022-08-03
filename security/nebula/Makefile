PORTNAME=	nebula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scalable overlay networking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	slack
GO_MODULE=	github.com/slackhq/nebula
GO_TARGET=	./cmd/nebula ./cmd/nebula-cert
GO_BUILDFLAGS=	-ldflags "-X main.Build=${PORTVERSION}"
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	bin/nebula \
		bin/nebula-cert \
		etc/${PORTNAME}/config.yml.example

post-patch:
	${REINPLACE_CMD} -e s,/etc/nebula,${PREFIX}/etc/${PORTNAME}, \
		-e /dev:/s/nebula1/tun1/ \
		${WRKSRC}/examples/config.yml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/config.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.example

.include <bsd.port.mk>
