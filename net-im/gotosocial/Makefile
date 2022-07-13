PORTNAME=	gotosocial
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES?=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${DISTVERSION}/:web
DISTFILES?=	${PORTNAME}_${DISTVERSION}_web-assets.tar.gz:web

MAINTAINER=	me+freebsd@igalic.co
COMMENT=	Golang fediverse server

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

# Note: we don't use go:modules, because this project vendors all deps
USES=		go
USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	superseriousbusiness

SUB_LIST=	DBDIR="${DBDIR}" \
		GROUP="${GROUPS}" \
		USER="${USERS}" \
		WWWDIR="${WWWDIR}"

USERS=		gotosocial
GROUPS=		gotosocial

DBDIR=		/var/db/${PORTNAME}

PLIST_SUB=	WWWDIR="${WWWDIR}"

# patch sample config for people who set a custom prefix
.if "${PREFIX}" != "${LOCALBASE}"
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/example/config.yaml
.endif

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		VERSION=${DISTVERSION} COMMIT=${GH_TAGNAME} scripts/build.sh )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in LICENSE README.md
	${INSTALL_DATA} ${WRKSRC}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample
	(cd ${WRKSRC}/../web && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/ )

.include <bsd.port.mk>
