# Created by: fabian.freyer@physik.tu-berlin.de
# $FreeBSD$

PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.11
CATEGORIES=	www

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	mholt

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/caddy etc/rc.d/caddy

do-build:
	@cd ${GO_WRKSRC}/${PORTNAME} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${GO_WRKSRC}/dist/init/freebsd/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
