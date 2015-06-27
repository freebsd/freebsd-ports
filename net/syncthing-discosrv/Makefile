# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-discosrv
PORTVERSION=	0.0.0.2015062601
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discovery server for syncthing

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing golang:gc
GH_PROJECT=	discosrv syncthing:st groupcache:gc
GH_TAGNAME=	4c705ff v${SYNCTHING_VER}:st 604ed57:gc

SYNCTHING_VER=	0.11.10

PLIST_FILES=	bin/syncthing-discosrv

USE_RC_SUBR=	syncthing-discosrv
USERS=		syncthing
GROUPS=		syncthing

STRIP=		# stripping can break go binaries

post-patch:
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/ ${WRKSRC}
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MV} ${WRKSRC_st} ${WRKSRC}/src/github.com/syncthing/syncthing
	@${MV} ${WRKSRC_gc} \
		${WRKSRC}/src/github.com/golang/groupcache

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/discosrv-${GH_TAGNAME} ${WRKSRC}/syncthing-discosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-discosrv ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
