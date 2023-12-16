PORTNAME=	gotosocial
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES?=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${DISTVERSION}/:web
DISTFILES?=	${PORTNAME}_${DISTVERSION}_web-assets.tar.gz:web

MAINTAINER=	freebsd@igalic.co
COMMENT=	Golang fediverse server
WWW=		https://docs.gotosocial.org/en/latest/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	https://gitlab.com/cznic/libc/-/issues/15

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	superseriousbusiness
USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./cmd/gotosocial
GO_BUILDFLAGS=	-trimpath -tags "netgo osusergo static_build kvformat ${WITH_DEBUG:Ddebugenv}" \
	-ldflags="${STRIP} -w -extldflags '-static' -X 'main.Version=${PKGVERSION}'"
CGO_ENABLED=	0

SUB_LIST=	DBDIR="${DBDIR}" \
		GROUP="${GROUPS}" \
		USER="${USERS}" \
		WWWDIR="${WWWDIR}"

USERS=		gotosocial
GROUPS=		gotosocial

DBDIR=		/var/db/${PORTNAME}

PLIST_SUB=	WWWDIR="${WWWDIR}"

post-install:
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
