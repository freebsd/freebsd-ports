# $FreeBSD$

PORTNAME=	teleport
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.9
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gravitational Teleport SSH

LICENSE=	APACHE20

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Uses 64bit types

BUILD_DEPENDS=	zip:archivers/zip

USES=		compiler gmake go

USE_GITHUB=	yes
GH_ACCOUNT=	gravitational
GH_TAG_COMMIT=	b3f4ecb

USE_RC_SUBR=	teleport

SUB_FILES=	pkg-message

PLIST_FILES=	bin/teleport \
		bin/tctl \
		bin/tsh \
		"@sample etc/teleport.yaml.sample"

# Extra assets are stored in the binary and must not be inadvertently removed
STRIP=
NOPRECIOUSMAKEVARS=	YES

GO_TELEPORT_SRC_DIR=	src/github.com/gravitational/teleport
PRE_GOPATH_DIR=	${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}

post-extract:
	@${MKDIR} ${WRKDIR}/${GO_TELEPORT_SRC_DIR}
	@${CP} -rpH ${WRKDIR}/${PRE_GOPATH_DIR}/vendor/* ${WRKDIR}/src/
	@${CP} -rpH ${WRKDIR}/${PRE_GOPATH_DIR}/* ${WRKDIR}/${GO_TELEPORT_SRC_DIR}/

post-patch:
	@${REINPLACE_CMD} -e 's|^GITREF=.*|GITREF=${GH_TAG_COMMIT}|' \
		${WRKDIR}/${GO_TELEPORT_SRC_DIR}/version.mk
	@${FIND} ${WRKDIR} -type f -exec ${SED} -i '' \
		-e 's|\/var\/lib|/var/db|g' \
		-e 's|\/usr\/bin\/hostname|/bin/hostname|g' {} +

do-build:
	@cd ${WRKDIR}/${GO_TELEPORT_SRC_DIR} && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} \
		CGO_ENABLED=1 GOPATH=${WRKDIR} \
		${GMAKE} full

do-install:
	${WRKDIR}/${GO_TELEPORT_SRC_DIR}/build/teleport configure > ${STAGEDIR}${PREFIX}/etc/teleport.yaml.sample
	@${SED} -i '' \
		-e "s|nodename: .*|nodename: |g" \
		-e "s|cluster-join-token||g" \
		${STAGEDIR}${PREFIX}/etc/teleport.yaml.sample
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
