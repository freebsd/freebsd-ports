# $FreeBSD$

PORTNAME=	concourse
PORTVERSION=	2.5.1
CATEGORIES=	net sysutils
MASTER_SITES=	LOCAL/dumbbell/concourse/
PKGNAMESUFFIX=	-fly

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for Concourse

LICENSE=	APACHE20

CONFLICTS_INSTALL=	fly

GO_CMD=		${LOCALBASE}/bin/go
GO_PKGNAME=	github.com/concourse/fly

USES=		go tar:xz

PLIST_FILES=	bin/fly

STRIP=		# stripping can break go binaries

# The build instructions for `fly` suggest to clone the global Concourse
# repository, which contains many Git submodules, including fly, and
# build from there. So basically:
#
#     git clone --recursive https://github.com/concourse/concourse.gi
#     cd concourse
#     export GOPATH=$PWD
#     cd src/github.com/concourse/fly
#     go build
#
# Therefore, the source archive contains the Concourse top-level
# repository and all its submodules. It's created using the
# create-src-archive below:
#
#     make create-src-archive
#
# Because it doesn't match the project layout USES=go expects, we
# override the post-extract and do-build targets to adapt the commands.
#
# `fly` version is set by default to "0.0.0-dev" in version/Version.go.
# Instead of patching the file, we use a linker flag to set the variable
# to the port's version.

post-extract:
	${LN} -sf ${WRKSRC}/src ${GO_WRKDIR_SRC}

do-build:
	(cd ${WRKDIR}; \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} \
		install -v -ldflags="-X github.com/concourse/fly/version.Version=${PORTVERSION}" ${GO_TARGET})

.include <bsd.port.mk>

.PHONY: create-src-archive
ARCHIVE_DIR=	${DISTDIR}/concourse-${PORTVERSION}
create-src-archive:
	${RM} -rf ${ARCHIVE_DIR}
	git clone --recursive -b v${PORTVERSION} \
		https://github.com/concourse/concourse.git \
		${ARCHIVE_DIR}
	${FIND} ${ARCHIVE_DIR} \( -name ".git*" -o -name "testdata" \) -depth -exec rm -rf {} \;
	${TAR} -cf - -C ${ARCHIVE_DIR:H} ${ARCHIVE_DIR:T} | ${XZ_CMD} > ${ARCHIVE_DIR}.tar.xz
	${RM} -rf ${ARCHIVE_DIR}
	${MAKE} makesum
