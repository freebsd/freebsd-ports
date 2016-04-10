# $FreeBSD$

PORTNAME=	syncthing-inotify
PORTVERSION=	0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing inotify monitor

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing cenkalti:backoff zillode:notify
GH_PROJECT=	backoff:backoff notify:notify
GH_TAGNAME=	32cd0c5:backoff bef4d0b:notify

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/syncthing-inotify

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/cenkalti
	@${MKDIR} ${WRKSRC}/src/github.com/zillode
	@${MV} ${WRKSRC_backoff} \
		${WRKSRC}/src/github.com/cenkalti/backoff
	@${MV} ${WRKSRC_notify} \
		${WRKSRC}/src/github.com/zillode/notify

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-inotify-${PORTVERSION} ${WRKSRC}/syncthing-inotify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-inotify ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
