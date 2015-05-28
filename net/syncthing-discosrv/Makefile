# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-discosrv
PORTVERSION=	0.0.0.2015022401
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discovery server for syncthing

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing golang:gc
GH_PROJECT=	discosrv syncthing:st groupcache:gc
GH_TAGNAME=	4e1240a v${SYNCTHING_VER}:st d2a1805:gc

SYNCTHING_VER=	0.11.5

PLIST_FILES=	bin/syncthing-discosrv

USE_RC_SUBR=	syncthing-discosrv
USERS=		syncthing
GROUPS=		syncthing

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/github.com/bkaradzic
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/juju
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MKDIR} ${WRKSRC}/src/github.com/syndtr
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/calmh \
		${WRKSRC}/src/github.com
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/bkaradzic/go-lz4 \
		${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/juju/ratelimit \
		${WRKSRC}/src/github.com/juju
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/syndtr/goleveldb \
		${WRKSRC}/src/github.com/syndtr
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/syndtr/gosnappy \
		${WRKSRC}/src/github.com/syndtr
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/golang.org/x/crypto \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/golang.org/x/text \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_st} \
		${WRKSRC}/src/github.com/syncthing/syncthing
	@${MV} ${WRKSRC}/src/github.com/syncthing/syncthing/Godeps/_workspace/src/github.com/syncthing/protocol \
		${WRKSRC}/src/github.com/syncthing/protocol
	@${MV} ${WRKSRC_gc} \
		${WRKSRC}/src/github.com/golang/groupcache

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/discosrv-${GH_TAGNAME} ${WRKSRC}/syncthing-discosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-discosrv ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
