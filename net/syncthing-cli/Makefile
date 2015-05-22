# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-cli
PORTVERSION=	0.1.0.2015050601
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GH \
		https://github.com/syncthing/syncthing/archive/v${SYNCTHING_VER}.tar.gz?dummy=/:group2 \
		https://codeload.github.com/AudriusButkevicius/cli/legacy.tar.gz/7f561c7?dummy=/:group3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		syncthing-${SYNCTHING_VER}${EXTRACT_SUFX}:group2 \
		AudriusButkevicius-cli-7f561c7${EXTACT_SUFX}:group3

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing CLI

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing
GH_PROJECT=	syncthing-cli
GH_TAGNAME=	51ec7bb30c3ccb92a3c4616ef00be3b3db739afe

SYNCTHING_VER=	0.11.5

PLIST_FILES=	bin/syncthing-cli

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MKDIR} ${WRKSRC}/src/github.com/AudriusButkevicius
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKDIR}/AudriusButkevicius-cli-7f561c7 \
		${WRKSRC}/src/github.com/AudriusButkevicius/cli
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/golang.org/x/crypto \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/golang.org/x/text \
		${WRKSRC}/src/golang.org/x
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/bkaradzic/go-lz4 \
		${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/calmh \
		${WRKSRC}/src/github.com/calmh
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER} \
		${WRKSRC}/src/github.com/syncthing/syncthing
	@${MV} ${WRKSRC}/src/github.com/syncthing/syncthing/Godeps/_workspace/src/github.com/syncthing/protocol \
		${WRKSRC}/src/github.com/syncthing/protocol

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-cli-${GH_TAGNAME} ${WRKSRC}/syncthing-cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-cli ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
