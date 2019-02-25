# $FreeBSD$

PORTNAME=		ssllabs-scan
DISTVERSIONPREFIX=	v
DISTVERSION=		1.5.0
CATEGORIES=		security net ipv6

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Command-line tool to use the SSL Labs API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	ssllabs

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@(cd ${GO_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} -o bin/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
