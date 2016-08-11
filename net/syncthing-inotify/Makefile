# $FreeBSD$

PORTNAME=	syncthing-inotify
PORTVERSION=	0.8.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing inotify monitor

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing cenkalti:backoff zillode:notify syncthing:ignore
GH_PROJECT=	backoff:backoff notify:notify syncthing:ignore
GH_TAGNAME=	9831e1e:backoff 2da5cc9:notify v0.13.4:ignore

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/syncthing-inotify

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/cenkalti
	@${MKDIR} ${WRKSRC}/src/github.com/zillode
	@${MKDIR} ${WRKSRC}/src/github.com/syncthing
	@${MV} ${WRKSRC_backoff} \
		${WRKSRC}/src/github.com/cenkalti/backoff
	@${MV} ${WRKSRC_notify} \
		${WRKSRC}/src/github.com/zillode/notify
	@${MV} ${WRKSRC_ignore} \
		${WRKSRC}/src/github.com/syncthing/syncthing

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-inotify-${PORTVERSION} ${WRKSRC}/syncthing-inotify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-inotify ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
