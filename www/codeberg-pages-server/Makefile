PORTNAME=	codeberg-pages-server
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/Codeberg/pages-server/archive/
DISTFILES=	${DISTVERSIONFULL}.zip

MAINTAINER=	orville@anislet.dev
COMMENT=	Codeberg Pages Server
WWW=		https://codeberg.org/Codeberg/pages-server

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.24,modules
USE_RC_SUBR=	codeberg-pages-server

GO_MODULE=	codeberg.org/codeberg/pages
GO_MOD_DIST=	https://codeberg.org/Codeberg/pages-server/raw/tag/${DISTVERSIONFULL}/
GO_TARGET=	codeberg.org/codeberg/pages:codeberg-pages-server
GO_BUILDFLAGS+=	-ldflags=" \
		${STRIP} -w \
		-extldflags '-static' \
		-X codeberg.org/codeberg/pages/server/version.Version=${DISTVERSIONFULL}"
GO_BUILDFLAGS+=	-tags=" \
		sqlite \
		sqlite_unlock_notify \
		netgo"

WRKSRC=		${WRKDIR}/pages-server

USERS=		www
GROUPS=		www

post-build:
	@${WRKDIR}/bin/codeberg-pages-server --help | \
		${SETENV} XDG_CACHE_HOME=${WRKDIR}/.cache ${GO_ENV} \
		${GO_CMD} run ${FILESDIR}/config-generater.go > \
		${WRKSRC}/codeberg-pages-server-config.in

post-install:
	${INSTALL} -m0600 ${WRKSRC}/codeberg-pages-server-config.in \
		${STAGEDIR}${PREFIX}/etc/rc.conf.d/codeberg-pages-server.sample

	@${MKDIR} ${STAGEDIR}/var/db/codeberg-pages-server

.include <bsd.port.mk>
