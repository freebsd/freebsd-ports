# $FreeBSD$

PORTNAME=	miniflux
DISTVERSION=	2.0.10
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Miniflux is a self-hosted software to read RSS/Atom/JSON feeds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USERS=	miniflux
GROUPS=	miniflux

USES=		go pgsql
WANT_PGSQL=	client

USE_RC_SUBR=	miniflux

USE_GITHUB=	yes
GH_ACCOUNT=	miniflux

GO_PKGNAME=	github.com/miniflux/${PORTNAME}

OPTIONS_DEFINE=	PGSQL_SERVER
OPTIONS_DEFAULT=
PGSQL_SERVER_DESC=	Install the PostgreSQL Server Component
PGSQL_SERVER_VARS=	WANT_PGSQL=server

.include <bsd.port.options.mk>

post-install:
		${INSTALL_DATA} ${FILESDIR}/miniflux.env.sample \
			${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
