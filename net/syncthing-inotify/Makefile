# $FreeBSD$

PORTNAME=	syncthing-inotify
PORTVERSION=	0.8.7
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing inotify monitor

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing 
GH_SUBDIR=	src/github.com/syncthing/syncthing-inotify
PLIST_FILES=	bin/syncthing-inotify

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} ; ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-inotify ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
