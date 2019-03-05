# $FreeBSD$

PORTNAME=	log-courier
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
CATEGORIES=	sysutils

MAINTAINER=	vikashb@where-ever.za.net
COMMENT=	Lightweight log shipper with Logstash integration

LICENSE=	APACHE20

BROKEN=		fails to build

BUILD_DEPENDS=	go:lang/go

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	driskell
GO_PKGNAME=	github.com/driskell/log-courier

USE_RC_SUBR=	log-courier
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/examples/example-json.conf \
		${STAGEDIR}${PREFIX}/etc/log-courier.conf.example

.include <bsd.port.mk>
