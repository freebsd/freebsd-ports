# $FreeBSD$

PORTNAME=	miniflux
DISTVERSION=	2.0.18
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Self-hosted software to read RSS/Atom/JSON feeds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules

USERS=	miniflux
GROUPS=	miniflux

WANT_PGSQL=	client
USE_RC_SUBR=	miniflux

USE_GITHUB=	yes
GH_ACCOUNT=	miniflux

GO_PKGNAME=	miniflux.app
GO_TARGET=	:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X miniflux.app/version.Version=${DISTVERSION} \
		-X miniflux.app/version.BuildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ')"

OPTIONS_DEFINE=		PGSQL_SERVER
PGSQL_SERVER_DESC=	Install the PostgreSQL Server Component
PGSQL_SERVER_VARS=	WANT_PGSQL=server,contrib

post-install:
	${INSTALL_MAN} ${WRKSRC}/miniflux.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_DATA} ${FILESDIR}/miniflux.env.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
