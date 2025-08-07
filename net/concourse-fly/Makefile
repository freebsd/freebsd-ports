PORTNAME=	concourse
PORTVERSION=	6.7.1
PORTREVISION=	28
CATEGORIES=	net sysutils
MASTER_SITES=	LOCAL/dumbbell/concourse/
PKGNAMESUFFIX=	-fly

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for Concourse
WWW=		https://concourse-ci.org/

LICENSE=	APACHE20

USES=		cpe go:modules tar:xz

CPE_VENDOR=	pivotal_software

GO_TARGET=	./cmd/concourse:fly
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/concourse/concourse.Version=${PORTVERSION}"
CGO_CFLAGS=	-I.

CONFLICTS_INSTALL=	concourse fly # bin/fly

PLIST_FILES=	bin/fly

# The build instructions for `fly` suggest to clone the global Concourse
# repository, which contains many Git submodules, including fly, and
# build from there. So basically:
#
#     git clone --recursive https://github.com/concourse/concourse.git
#     cd concourse/fly
#     go build
#
# Unfortunately, this is difficult to integrate as is with the Ports framework:
#   * Some submodules are hosted on services other than GitHub
#   * Third-party Go dependencies are not Git submodules
#
# We created the `create-src-archive` to create a self-contained
# source archive because the Concourse does not provide one. This
# source archive contains the Git submodules and the third-party Go
# dependencies, fetched using `go mod vendor`.
#
# It is created using the `create-src-archive` target below:
#
#     make create-src-archive
#
# `fly` version is set by default to "0.0.0-dev" in version/Version.go.
# Instead of patching the file, we use a linker flag to set the variable
# to the port's version.

.PHONY: create-src-archive
ARCHIVE_DIR=	${DISTDIR}/concourse-${PORTVERSION}
create-src-archive:
	${RM} -rf ${ARCHIVE_DIR}
	git clone --recursive -b v${PORTVERSION} \
		https://github.com/concourse/concourse.git \
		${ARCHIVE_DIR}
	GOPATH=$$(mktemp concourse-gopath.XXXX) && \
	(cd ${ARCHIVE_DIR} && \
	 ${GO_CMD} mod vendor) && \
	${FIND} "$$GOPATH" -exec ${CHMOD} u+w {} \; && \
	${RM} -rf "$$GOPATH"
	${FIND} ${ARCHIVE_DIR} \( -name ".git*" -o -name "testdata" \) -depth -exec ${RM} -rf {} \;
	${TAR} -cf - -C ${ARCHIVE_DIR:H} ${ARCHIVE_DIR:T} | ${XZ_CMD} > ${ARCHIVE_DIR}.tar.xz
	${RM} -rf ${ARCHIVE_DIR}
	${MAKE} makesum

.include <bsd.port.mk>
