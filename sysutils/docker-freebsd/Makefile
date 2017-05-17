# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	docker-freebsd
PORTVERSION=	20150625
CATEGORIES=	sysutils

MAINTAINER=	amutu@amutu.com
COMMENT=	Docker containment system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.4:lang/go \
		bash:shells/bash \
		sqlite3:databases/sqlite3
RUN_DEPENDS=	go>=1.4:lang/go \
		bash:shells/bash \
		sqlite3:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	kvasdopil
GH_PROJECT=	docker
GH_TAGNAME=	582db78

PLIST_FILES=	bin/docker
USE_RC_SUBR=	docker

do-build:
	@cd ${WRKSRC} && export AUTO_GOPATH=1 && export DOCKER_GITCOMMIT=${GH_TAGNAME} && ./hack/make.sh binary

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bundles/latest/binary/docker ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
