# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-discosrv
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discovery server for syncthing

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing
GH_PROJECT=	discosrv

PLIST_FILES=	bin/syncthing-discosrv

USE_RC_SUBR=	syncthing-discosrv
USERS=		syncthing
GROUPS=		syncthing

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${MV} .gitignore CONTRIBUTORS LICENSE README.md build.sh \
		clean.go db.go main.go psql.go ql.go querysrv.go stats.go \
		vendor \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build
	@${MV} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/discosrv ${WRKSRC}/syncthing-discosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-discosrv ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
