# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing
PORTVERSION=	0.10.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_RC_SUBR=	syncthing
PLIST_FILES=	bin/syncthing
PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${PORTNAME}/${PORTNAME} ; \
		${MV} CONTRIBUTORS Godeps LICENSE README.md build.go build.sh \
		assets cmd gui internal protocol src/github.com/${PORTNAME}/${PORTNAME}

do-build:
	# timestamp here refers to source, not build time
	cd ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME} ; \
		${SETENV} GOPATH=${WRKSRC} go run build.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/syncthing \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in CONTRIBUTORS LICENSE README.md
	${INSTALL_MAN} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
