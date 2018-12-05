# $FreeBSD$

PORTNAME=	syncthing
PORTVERSION=	0.14.54
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
USE_RC_SUBR=	syncthing syncthing-discosrv syncthing-relaysrv syncthing-relaypoolsrv
BINS=		stbench stcli stcompdirs stdisco stdiscosrv stevents stfileinfo \
		stfinddevice stgenfiles stindex strelaypoolsrv strelaysrv \
		stsigtool sttestutil stvanity stwatchfile syncthing

.for x in ${BINS}
PLIST_FILES+=	bin/${x}
.endfor

PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} CGO_ENABLED=0 go run build.go -no-upgrade=true -version v${PORTVERSION}
	@${MV} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/testutil \
		${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/sttestutil

do-install:
.for x in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/${x} \
		${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in AUTHORS LICENSE README.md
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
