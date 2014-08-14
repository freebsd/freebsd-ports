# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing
PORTVERSION=	0.9.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/:group1 \
		https://bitbucket.org/kardianos/osext/get/:group2 \
		https://crypto.go.googlecode.com/archive/:group3 \
		https://text.go.googlecode.com/archive/:group4 \
		https://snappy-go.googlecode.com/archive/:group5 \
		https://codeload.github.com/bkaradzic/go-lz4/legacy.tar.gz/77e2ba8?dummy=/:group6 \
		https://codeload.github.com/calmh/xdr/legacy.tar.gz/e1714bb?dummy=/:group7 \
		https://codeload.github.com/juju/ratelimit/legacy.tar.gz/f9f36d1?dummy=/:group8 \
		https://codeload.github.com/syndtr/goleveldb/legacy.tar.gz/2b4cbca?dummy=/:group9 \
		https://codeload.github.com/vitrun/qart/legacy.tar.gz/ccb109c?dummy=/:group10
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:group1 \
		5d3ddcf53a50${EXTRACT_SUFX}:group2 \
		f3cebac2bd11c2bf03c15bfa4c66688ad02a0a40${EXTRACT_SUFX}:group3 \
		d65bffbc88a153d23a6d2a864531e6e7c2cde59b${EXTRACT_SUFX}:group4 \
		12e4b4183793ac4b061921e7980845e750679fd0${EXTRACT_SUFX}:group5 \
		bkaradzic-go-lz4-77e2ba8${EXTRACT_SUFX}:group6 \
		calmh-xdr-e1714bb${EXTRACT_SUFX}:group7 \
		juju-ratelimit-f9f36d1${EXTACT_SUFX}:group8 \
		syndtr-goleveldb-2b4cbca${EXTRACT_SUFX}:group9 \
		vitrun-qart-ccb109c${EXTRACT_SUFX}:group10

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go \
		bash:${PORTSDIR}/shells/bash

USE_RC_SUBR=	syncthing
PLIST_FILES=	bin/syncthing bin/stindex bin/stevents
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
		${MV} ${WRKDIR}/crypto.go-f3cebac2bd11/ src/code.google.com/p/go.crypto ; \
		${MV} ${WRKDIR}/snappy-go-12e4b4183793 src/code.google.com/p/snappy-go ; \
		${MV} ${WRKDIR}/text.go-d65bffbc88a1 src/code.google.com/p/go.text ; \
		${MV} ${WRKDIR}/bkaradzic-go-lz4-77e2ba8 src/github.com/bkaradzic/go-lz4 ; \
		${MV} ${WRKDIR}/calmh-xdr-e1714bb src/github.com/calmh/xdr ; \
		${MV} ${WRKDIR}/juju-ratelimit-f9f36d1 src/github.com/juju/ratelimit ; \
		${MV} ${WRKDIR}/syndtr-goleveldb-2b4cbca src/github.com/syndtr/goleveldb ; \
		${MV} ${WRKDIR}/vitrun-qart-ccb109c src/github.com/vitrun/qart ; \
		${CP} -r lamport luhn beacon scanner versioner files \
		protocol auto config discover events logger model osutil \
		upgrade upnp src/github.com/syncthing/syncthing

do-build:
	cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} bash ./build.sh

do-install:
.for x in stevents stindex syncthing
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${x} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in CONTRIBUTORS LICENSE README.md
	${INSTALL_MAN} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
