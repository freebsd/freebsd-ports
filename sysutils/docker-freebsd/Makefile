# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	docker-freebsd
PORTVERSION=	20150625
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Docker containment system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build
DEPRECATED=	Broken for more than 9 months
EXPIRATION_DATE=	2020-01-10

BUILD_DEPENDS=	bash:shells/bash \
		sqlite3:databases/sqlite3
RUN_DEPENDS=	bash:shells/bash \
		sqlite3:databases/sqlite3

USES=		go:run

USE_GITHUB=	yes
GH_ACCOUNT=	kvasdopil
GH_PROJECT=	docker
GH_TAGNAME=	582db78

PLIST_FILES=	bin/docker
USE_RC_SUBR=	docker

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} AUTO_GOPATH=1 DOCKER_GITCOMMIT=${GH_TAGNAME} ./hack/make.sh binary

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bundles/latest/binary/docker ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
