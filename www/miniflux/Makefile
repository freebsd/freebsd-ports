# $FreeBSD$

PORTNAME=	miniflux
DISTVERSION=	2.0.13
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Miniflux is a self-hosted software to read RSS/Atom/JSON feeds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go pgsql

USERS=	miniflux
GROUPS=	miniflux

WANT_PGSQL=	client
USE_RC_SUBR=	miniflux

USE_GITHUB=	yes
GH_ACCOUNT=	miniflux

GO_PKGNAME=	miniflux.app
GO_TARGET=	${GO_PKGNAME}
GO_BUILDFLAGS=	-ldflags="-X miniflux.app/version.Version=${DISTVERSION} \
		-X miniflux.app/version.BuildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ')"

OPTIONS_DEFINE=		PGSQL_SERVER
OPTIONS_DEFAULT=
PGSQL_SERVER_DESC=	Install the PostgreSQL Server Component
PGSQL_SERVER_VARS=	WANT_PGSQL=server

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/miniflux.app ${STAGEDIR}${PREFIX}/bin/miniflux
	${INSTALL_MAN} ${WRKSRC}/miniflux.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install:
	${INSTALL_DATA} ${FILESDIR}/miniflux.env.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
