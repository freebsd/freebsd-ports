# $FreeBSD$

PORTNAME=	teleport
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.7
CATEGORIES=	security

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Gravitational Telport SSH

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go \
		${LOCALBASE}/bin/zip:archivers/zip

USES=		compiler gmake

USE_GITHUB=	yes
GH_ACCOUNT=	gravitational
GH_TAG_COMMIT=	b3f4ecb

USE_RC_SUBR=	teleport

SUB_FILES=	pkg-message

PLIST_FILES=	bin/teleport \
		bin/tctl \
		bin/tsh \
		etc/teleport.yaml.sample

STRIP=

GO_TELEPORT_SRC_DIR=	src/github.com/gravitational/teleport
PRE_GOPATH_DIR=	${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}

post-extract:
	@${MKDIR} ${WRKDIR}/${GO_TELEPORT_SRC_DIR}
	@${CP} -rp ${WRKDIR}/${PRE_GOPATH_DIR}/vendor/* ${WRKDIR}/src/
	@${CP} -rp ${WRKDIR}/${PRE_GOPATH_DIR}/* ${WRKDIR}/${GO_TELEPORT_SRC_DIR}/

post-patch:
	@${REINPLACE_CMD} -e "s|%%GH_TAG_COMMIT%%|${GH_TAG_COMMIT}|g" \
		${WRKDIR}/${GO_TELEPORT_SRC_DIR}/version.mk

do-build:
	@cd ${WRKDIR}/${GO_TELEPORT_SRC_DIR} && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} \
		CGO_ENABLED=1 GOPATH=${WRKDIR} \
		${GMAKE} -s full

do-install:
	${WRKDIR}/${GO_TELEPORT_SRC_DIR}/build/teleport configure > ${STAGEDIR}${PREFIX}/etc/teleport.yaml.sample
	${INSTALL_PROGRAM} ${WRKDIR}/${GO_TELEPORT_SRC_DIR}/build/teleport ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/${GO_TELEPORT_SRC_DIR}/build/tsh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/${GO_TELEPORT_SRC_DIR}/build/tctl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
