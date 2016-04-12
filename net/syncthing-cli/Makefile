# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing-cli
PORTVERSION=	0.1.0.2015092201
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Syncthing CLI

BUILD_DEPENDS=	go>=1.5:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing
GH_TAGNAME=	9594d39

PLIST_FILES=	bin/syncthing-cli

STRIP=		# stripping can break go binaries

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC}/Godeps/_workspace:${WRKSRC} go build
	@${MV} ${WRKSRC}/syncthing-cli-${GH_TAGNAME} ${WRKSRC}/syncthing-cli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing-cli ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
