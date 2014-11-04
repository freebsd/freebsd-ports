# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-discosrv
PORTVERSION=	0.0.0.2014110101
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/syncthing/syncthing/archive/v${SYNCTHING_VER}.tar.gz?dummy=/:group2 \
		https://codeload.github.com/golang/groupcache/legacy.tar.gz/${GROUPCACHE_COMMIT}?dummy=/:group3
DISTFILES=	syncthing-discosrv-${PORTVERSION}.tar.gz:group1 \
		syncthing-${SYNCTHING_VER}${EXTRACT_SUFX}:group2 \
		golang-groupcache-${GROUPCACHE_COMMIT}${EXTRACT_SUFX}:group3

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discovery server for syncthing

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

GH_ACCOUNT=	syncthing
GH_PROJECT=	discosrv
GH_COMMIT=	fcba610d30efa662d4435b3127300171aae7b0e9
GH_TAGNAME=	${GH_COMMIT}

SYNCTHING_VER=	0.10.4
GROUPCACHE_COMMIT=	d2a1805

WRKSRC=		${WRKDIR}/discosrv-${GH_COMMIT}

PLIST_FILES=	bin/syncthing-discosrv

USE_RC_SUBR=	syncthing-discosrv
USERS=		syncthing
GROUPS=		syncthing

post-patch:
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/github.com/bkaradzic
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/juju
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MKDIR} ${WRKSRC}/src/github.com/syndtr
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/calmh \
		${WRKSRC}/src/github.com
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/bkaradzic/go-lz4 \
		${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/juju/ratelimit \
		${WRKSRC}/src/github.com/juju
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/syndtr/goleveldb \
		${WRKSRC}/src/github.com/syndtr
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/code.google.com/p/go.text \
		${WRKSRC}/src/code.google.com/p
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/code.google.com/p/snappy-go \
		${WRKSRC}/src/code.google.com/p
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER} \
		${WRKSRC}/src/github.com/syncthing/syncthing
	@${MV} ${WRKDIR}/golang-groupcache-${GROUPCACHE_COMMIT} \
		${WRKSRC}/src/github.com/golang/groupcache

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/discosrv-${GH_COMMIT} ${WRKSRC}/syncthing-discosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-discosrv ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
