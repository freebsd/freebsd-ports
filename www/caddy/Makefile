# Created by: fabian.freyer@physik.tu-berlin.de
# $FreeBSD$

PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	mholt

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./caddy

SUB_FILES=	pkg-message
PLIST_FILES=	bin/caddy etc/rc.d/caddy

OPTIONS_DEFINE=	TELEMETRY

TELEMETRY_DESC=	Enable telemetry support
TELEMETRY_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-disable-telemetry

post-install:
	${INSTALL_SCRIPT} ${GO_WRKSRC}/dist/init/freebsd/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
