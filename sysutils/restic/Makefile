# $FreeBSD$

PORTNAME=	restic
PORTVERSION=	0.1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Restic backup program

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	restic:DEFAULT,chunker juju:errors golang:crypto
GH_PROJECT=	chunker:chunker errors:errors crypto:crypto
GH_TAGNAME=	16a28ff:chunker 1b5e39b:errors 74f810a:crypto

STRIP=		# stripping can break go binaries

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in CONTRIBUTING.md Godeps LICENSE Makefile README.md VERSION Vagrantfile appveyor.yml archiver.go archiver_int_test.go archiver_test.go backend build.go cache.go cache_test.go checker cmd crypto debug doc doc.go filter fuse lock.go lock_test.go lock_unix.go lock_windows.go node.go node_darwin.go node_freebsd.go node_linux.go node_openbsd.go node_test.go node_unix.go node_windows.go pack pipe progress.go repository restorer.go run_integration_tests.go run_tests.go snapshot.go snapshot_test.go test tree.go tree_test.go walk.go walk_test.go
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/restic/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/juju
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_chunker} ${WRKSRC}/src/github.com/restic/chunker
	@${MV} ${WRKSRC_errors} ${WRKSRC}/src/github.com/juju/errors
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go run build.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
