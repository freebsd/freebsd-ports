# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing
PORTVERSION=	0.9.18
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/:group1 \
		https://bitbucket.org/kardianos/osext/get/:group2 \
		LOCAL/swills:group3 \
		LOCAL/swills:group4 \
		LOCAL/swills:group5 \
		https://codeload.github.com/bkaradzic/go-lz4/legacy.tar.gz/93a831d?dummy=/:group6 \
		https://codeload.github.com/calmh/xdr/legacy.tar.gz/e1714bb?dummy=/:group7 \
		https://codeload.github.com/juju/ratelimit/legacy.tar.gz/f9f36d1?dummy=/:group8 \
		https://codeload.github.com/syndtr/goleveldb/legacy.tar.gz/9bca75c?dummy=/:group9 \
		https://codeload.github.com/vitrun/qart/legacy.tar.gz/ccb109c?dummy=/:group10 \
		LOCAL/swills:group11 \
		LOCAL/swills:group12
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:group1 \
		5d3ddcf53a50${EXTRACT_SUFX}:group2 \
		text.go-024681b033be${EXTRACT_SUFX}:group3 \
		snappy-go-12e4b4183793${EXTRACT_SUFX}:group4 \
		crypto.go-31393df5baea${EXTRACT_SUFX}:group5 \
		bkaradzic-go-lz4-77e2ba8${EXTRACT_SUFX}:group6 \
		calmh-xdr-e1714bb${EXTRACT_SUFX}:group7 \
		juju-ratelimit-f9f36d1${EXTACT_SUFX}:group8 \
		syndtr-goleveldb-9bca75c${EXTRACT_SUFX}:group9 \
		vitrun-qart-ccb109c${EXTRACT_SUFX}:group10 \
		tools.go-7a99b946364f${EXTRACT_SUFX}:group11 \
		net.go-90e232e2462d${EXTRACT_SUFX}:group12

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_RC_SUBR=	syncthing
PLIST_FILES=	bin/syncthing
PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

post-patch:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/build.sh
	cd ${WRKSRC} ; \
		${MKDIR} src/code.google.com/p \
			src/bitbucket.org/kardianos \
			src/github.com/bkaradzic \
			src/github.com/calmh \
			src/github.com/juju \
			src/github.com/syndtr \
			src/github.com/vitrun \
			src/github.com/syncthing/syncthing ; \
		${MV} ${WRKDIR}/kardianos-osext-5d3ddcf53a50 ${WRKSRC}/src/bitbucket.org/kardianos/osext ; \
		${MV} ${WRKDIR}/crypto.go-31393df5baea/ src/code.google.com/p/go.crypto ; \
		${MV} ${WRKDIR}/snappy-go-12e4b4183793 src/code.google.com/p/snappy-go ; \
		${MV} ${WRKDIR}/text.go-024681b033be src/code.google.com/p/go.text ; \
		${MV} ${WRKDIR}/tools.go-7a99b946364f src/code.google.com/p/go.tools ; \
		${MV} ${WRKDIR}/net.go-90e232e2462d src/code.google.com/p/go.net ; \
		${MV} ${WRKDIR}/bkaradzic-go-lz4-93a831d src/github.com/bkaradzic/go-lz4 ; \
		${MV} ${WRKDIR}/calmh-xdr-e1714bb src/github.com/calmh/xdr ; \
		${MV} ${WRKDIR}/juju-ratelimit-f9f36d1 src/github.com/juju/ratelimit ; \
		${MV} ${WRKDIR}/syndtr-goleveldb-9bca75c src/github.com/syndtr/goleveldb ; \
		${MV} ${WRKDIR}/vitrun-qart-ccb109c src/github.com/vitrun/qart ; \
		${CP} -r lamport luhn beacon scanner versioner files \
		protocol auto config discover events logger model osutil ignore stats fnmatch cmd \
		upgrade upnp src/github.com/syncthing/syncthing

do-build:
	# timestamp here refers to source, not build time
	cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build -ldflags "-w -X main.Version v${PORTVERSION} -X main.BuildStamp 1411588890 -X main.BuildUser ${USER} -X main.BuildHost ${HOST}" github.com/syncthing/syncthing/cmd/syncthing
	${STRIP_CMD} ${WRKSRC}/syncthing

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in CONTRIBUTORS LICENSE README.md
	${INSTALL_MAN} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
