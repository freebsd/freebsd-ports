# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	docker
PORTVERSION=	06232015
CATEGORIES=	net-mgmt

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Docker containment system

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git \
		sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		sqlite3:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	kvasdopil
GH_TAGNAME=	582db78

PLIST_FILES=	bin/docker
USE_RC_SUBR=	docker

do-build:
	@cd ${WRKSRC} && export AUTO_GOPATH=1 && ./hack/make.sh binary

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/bundles/latest/binary/docker ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
