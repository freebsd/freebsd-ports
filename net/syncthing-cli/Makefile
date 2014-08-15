# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-cli
PORTVERSION=	0.0.0.2014081401
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://codeload.github.com/AudriusButkevicius/cli/legacy.tar.gz/7f561c7?dummy=/:group2 \
		https://github.com/syncthing/syncthing/archive/v0.9.4.tar.gz?dummy=/:group3 \
		LOCAL/swills:group4 \
		LOCAL/swills:group5 \
		https://codeload.github.com/bkaradzic/go-lz4/legacy.tar.gz/77e2ba8?dummy=/:group6 \
		https://codeload.github.com/calmh/xdr/legacy.tar.gz/e1714bb?dummy=/:group7
DISTFILES=	syncthing-cli-0.0.0.2014081401.tar.gz:group1 \
		AudriusButkevicius-cli-7f561c7${EXTACT_SUFX}:group2 \
		syncthing-0.9.4${EXTRACT_SUFX}:group3 \
		crypto.go-f3cebac2bd11${EXTRACT_SUFX}:group4 \
		text.go-d65bffbc88a1${EXTRACT_SUFX}:group5 \
		bkaradzic-go-lz4-77e2ba8${EXTRACT_SUFX}:group6 \
		calmh-xdr-e1714bb${EXTRACT_SUFX}:group7

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing CLI

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

GH_ACCOUNT=	syncthing
GH_PROJECT=	syncthing-cli
GH_COMMIT=	7dab84f
GH_TAGNAME=	${GH_COMMIT}

WRKSRC=		${WRKDIR}/${PORTNAME}-7dab84f6edfbd873c5addac1c564fa1f64d0ff29

PLIST_FILES=	bin/syncthing-cli

post-patch:
	cd ${WRKSRC} ; \
		${MKDIR} src/github.com/AudriusButkevicius ; \
		${MKDIR} src/github.com/syncthing/syncthing ; \
		${MKDIR} src/github.com/bkaradzic ; \
		${MKDIR} src/github.com/calmh ; \
		${MKDIR} src/code.google.com/p ; \
		${MV} ${WRKDIR}/AudriusButkevicius-cli-7f561c7 src/github.com/AudriusButkevicius/cli ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/config src/github.com/syncthing/syncthing/config ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/protocol src/github.com/syncthing/syncthing/protocol ; \
		${MV} ${WRKDIR}/crypto.go-f3cebac2bd11 src/code.google.com/p/go.crypto ; \
		${MV} ${WRKDIR}/text.go-d65bffbc88a1/ src/code.google.com/p/go.text ; \
		${MV} ${WRKDIR}/bkaradzic-go-lz4-77e2ba8 src/github.com/bkaradzic/go-lz4 ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/logger src/github.com/syncthing/syncthing ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/luhn src/github.com/syncthing/syncthing ; \
		${MV} ${WRKDIR}/calmh-xdr-e1714bb src/github.com/calmh/xdr

do-build:
	cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	${MV} ${WRKSRC}/syncthing-cli-7dab84f6edfbd873c5addac1c564fa1f64d0ff29 ${WRKSRC}/syncthing-cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-cli ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
