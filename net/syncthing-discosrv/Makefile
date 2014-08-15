# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-discosrv
PORTVERSION=	0.0.0.2014081401
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://codeload.github.com/juju/ratelimit/legacy.tar.gz/f9f36d1?dummy=/:group2 \
		https://github.com/syncthing/syncthing/archive/v0.9.4.tar.gz?dummy=/:group3 \
		https://codeload.github.com/calmh/xdr/legacy.tar.gz/e1714bb?dummy=/:group4 \
		LOCAL/swills:group5 \
		https://codeload.github.com/bkaradzic/go-lz4/legacy.tar.gz/77e2ba8?dummy=/:group6 \
		https://codeload.github.com/golang/groupcache/legacy.tar.gz/8b25adc?dummy=/:group7
DISTFILES=	syncthing-discosrv-0.0.0.2014081401.tar.gz:group1 \
		juju-ratelimit-f9f36d1${EXTACT_SUFX}:group2 \
		syncthing-0.9.4${EXTRACT_SUFX}:group3 \
		calmh-xdr-e1714bb${EXTRACT_SUFX}:group4 \
		text.go-d65bffbc88a1${EXTRACT_SUFX}:group5 \
		bkaradzic-go-lz4-77e2ba8${EXTRACT_SUFX}:group6 \
		golang-groupcache-8b25adc${EXTRACT_SUFX}:group7

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discovery server for syncthing

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

GH_ACCOUNT=	syncthing
GH_PROJECT=	discosrv
GH_COMMIT=	f2b3bb0
GH_TAGNAME=	${GH_COMMIT}

WRKSRC=		${WRKDIR}/discosrv-f2b3bb063f83f24d6c6e10013ea467d5967eb0cf

PLIST_FILES=	bin/syncthing-discosrv

post-patch:
	cd ${WRKSRC} ; \
		${MKDIR} src/github.com/juju ; \
		${MKDIR} src/github.com/calmh ; \
		${MKDIR} src/code.google.com/p ; \
		${MKDIR} src/github.com/bkaradzic ; \
		${MKDIR} src/github.com/syncthing/syncthing ; \
		${MKDIR} src/github.com/golang ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/discover src/github.com/syncthing/syncthing/ ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/beacon src/github.com/syncthing/syncthing/ ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/events src/github.com/syncthing/syncthing/ ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/logger src/github.com/syncthing/syncthing/ ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/protocol src/github.com/syncthing/syncthing/ ; \
		${MV} ${WRKDIR}/juju-ratelimit-f9f36d1 src/github.com/juju/ratelimit ; \
		${MV} ${WRKDIR}/calmh-xdr-e1714bb src/github.com/calmh/xdr ; \
		${MV} ${WRKDIR}/text.go-d65bffbc88a1/ src/code.google.com/p/go.text ; \
		${MV} ${WRKDIR}/bkaradzic-go-lz4-77e2ba8 src/github.com/bkaradzic/go-lz4 ; \
		${MV} ${WRKDIR}/golang-groupcache-8b25adc src/github.com/golang/groupcache ; \
		${MV} ${WRKDIR}/syncthing-0.9.4/luhn src/github.com/syncthing/syncthing

do-build:
	cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	${MV} ${WRKSRC}/discosrv-f2b3bb063f83f24d6c6e10013ea467d5967eb0cf ${WRKSRC}/syncthing-discosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-discosrv ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
