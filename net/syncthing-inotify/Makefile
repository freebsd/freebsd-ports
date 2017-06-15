# $FreeBSD$

PORTNAME=	syncthing-inotify
PORTVERSION=	0.8.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing inotify monitor

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing 
GH_TUPLE=	cenkalti:backoff:9831e1e:backoff/src/github.com/cenkalti/backoff \
		zillode:notify:2da5cc9:notify/src/github.com/zillode/notify \
		syncthing:syncthing:v0.13.4:ignore/src/github.com/syncthing/syncthing

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/syncthing-inotify

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-inotify-${PORTVERSION} ${WRKSRC}/syncthing-inotify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-inotify ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
