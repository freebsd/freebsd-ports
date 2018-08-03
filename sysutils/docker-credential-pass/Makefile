# $FreeBSD$

PORTNAME=	docker-credential-pass
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	sysutils

MAINTAINER=	dg@syrec.org
COMMENT=	Helper to use sysutils/password-store as Docker credentials store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go
RUN_DEPENDS=	${LOCALBASE}/bin/pass:sysutils/password-store

USE_GITHUB=	yes
GH_ACCOUNT=	docker
GH_PROJECT=	docker-credential-helpers
GH_SUBDIR=	src/github.com/docker/docker-credential-helpers

PLIST_FILES=	bin/docker-credential-pass

do-build:
	${CP} ${WRKSRC}/${GH_SUBDIR}/pass/cmd/main_linux.go ${WRKSRC}/${GH_SUBDIR}/pass/cmd/main_freebsd.go
	${CP} ${WRKSRC}/${GH_SUBDIR}/pass/pass_linux.go ${WRKSRC}/${GH_SUBDIR}/pass/pass_freebsd.go
	cd ${WRKSRC}/${GH_SUBDIR}/pass && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME} ./cmd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/pass/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
