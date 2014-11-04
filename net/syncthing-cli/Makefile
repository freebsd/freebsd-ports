# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-cli
PORTVERSION=	0.1.0.2014110101
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/syncthing/syncthing/archive/v${SYNCTHING_VER}.tar.gz?dummy=/:group2 \
		https://codeload.github.com/AudriusButkevicius/cli/legacy.tar.gz/7f561c7?dummy=/:group3
DISTFILES=	syncthing-cli-${PORTVERSION}${EXTRACT_SUFX}:group1 \
		syncthing-${SYNCTHING_VER}${EXTRACT_SUFX}:group2 \
		AudriusButkevicius-cli-7f561c7${EXTACT_SUFX}:group3

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing CLI

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

GH_ACCOUNT=	syncthing
GH_PROJECT=	syncthing-cli
GH_COMMIT=	c87be74a305ef6b3f05debde4df84c27e9005035
GH_TAGNAME=	${GH_COMMIT}

SYNCTHING_VER=	0.10.4

WRKSRC=		${WRKDIR}/syncthing-cli-${GH_COMMIT}

PLIST_FILES=	bin/syncthing-cli

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MKDIR} ${WRKSRC}/src/github.com/AudriusButkevicius
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKDIR}/AudriusButkevicius-cli-7f561c7 \
		${WRKSRC}/src/github.com/AudriusButkevicius/cli
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/code.google.com/p/go.crypto \
                ${WRKSRC}/src/code.google.com/p
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/code.google.com/p/go.text \
                ${WRKSRC}/src/code.google.com/p
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/bkaradzic/go-lz4 \
                ${WRKSRC}/src/github.com/bkaradzic
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER}/Godeps/_workspace/src/github.com/calmh \
		${WRKSRC}/src/github.com/calmh
	@${MV} ${WRKDIR}/syncthing-${SYNCTHING_VER} \
		${WRKSRC}/src/github.com/syncthing/syncthing

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-cli-${GH_COMMIT} ${WRKSRC}/syncthing-cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-cli ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
