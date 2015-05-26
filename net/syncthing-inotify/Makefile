# $FreeBSD$

PORTNAME=	syncthing-inotify
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/cenkalti/backoff/archive/6c45d6bc1e78d94431dff8fc28a99f20bafa355a.tar.gz?dummy=/:group2 \
		https://github.com/zillode/notify/archive/f06b1e3b795091f2e1414067b08e5f07332cdb05.tar.gz?dummy=/:group3
DISTFILES=	syncthing-syncthing-inotify-v${PORTVERSION}.tar.gz:group1 \
		cenkalti_backoff_6c45d6bc1e78d94431dff8fc28a99f20bafa355a.tar.gz:group2 \
		zillode_notify_f06b1e3b795091f2e1414067b08e5f07332cdb05.tar.gz:group3

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing inotify monitor

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing
GH_PROJECT=	syncthing-inotify

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/syncthing-inotify

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/cenkalti
	@${MKDIR} ${WRKSRC}/src/github.com/zillode
	@${MV} ${WRKDIR}/backoff-6c45d6bc1e78d94431dff8fc28a99f20bafa355a \
		${WRKSRC}/src/github.com/cenkalti/backoff
	@${MV} ${WRKDIR}/notify-f06b1e3b795091f2e1414067b08e5f07332cdb05 \
		${WRKSRC}/src/github.com/zillode/notify

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-inotify-${PORTVERSION} ${WRKSRC}/syncthing-inotify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-inotify ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
