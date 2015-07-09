# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-cli
PORTVERSION=	0.1.0.2015062701
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing CLI

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing AudriusButkevicius:audrius
GH_PROJECT=	syncthing:st cli:audrius
GH_TAGNAME=	eba2fb7 v${SYNCTHING_VER}:st 7f561c7:audrius

SYNCTHING_VER=	0.11.13

PLIST_FILES=	bin/syncthing-cli

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MKDIR} ${WRKSRC}/src/github.com/AudriusButkevicius
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKSRC_audrius} \
		${WRKSRC}/src/github.com/AudriusButkevicius/cli
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/golang.org/x/crypto \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/golang.org/x/text \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/bkaradzic/go-lz4 \
		${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKSRC_st}/Godeps/_workspace/src/github.com/calmh \
		${WRKSRC}/src/github.com/calmh
	@${MV} ${WRKSRC_st} \
		${WRKSRC}/src/github.com/syncthing/syncthing
	@${MV} ${WRKSRC}/src/github.com/syncthing/syncthing/Godeps/_workspace/src/github.com/syncthing/protocol \
		${WRKSRC}/src/github.com/syncthing/protocol

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-cli-${GH_TAGNAME} ${WRKSRC}/syncthing-cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-cli ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
