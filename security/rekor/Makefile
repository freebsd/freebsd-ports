PORTNAME=	rekor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.10
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Software Supply Chain Transparency Log ${${FLAVOR}_COMMENT}
WWW=		https://www.sigstore.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	client server
FLAVOR?=	${FLAVORS:[1]}
client_PKGNAMESUFFIX=	-client
client_COMMENT=		(client only)
client_PLIST=	${.CURDIR}/pkg-plist.client
server_PKGNAMESUFFIX=	-server
server_COMMENT=		(server only)
server_PLIST=	${.CURDIR}/pkg-plist.server

USES=		cpe go:1.24,modules
CPE_VENDOR=	linuxfoundation
.if ${FLAVOR} == server
USE_RC_SUBR=	rekor
.endif

GO_MODULE=	github.com/sigstore/rekor
.if ${FLAVOR} == client
GO_TARGET=	./cmd/rekor-cli
.elif ${FLAVOR} == server
GO_TARGET=	./cmd/rekor-server \
		./cmd/backfill-index \
		./cmd/cleanup-index \
		./cmd/copy-index
.endif
GO_BUILDFLAGS=	-ldflags="\
	-X sigs.k8s.io/release-utils/version.gitVersion=$(DISTVERSION) \
	-X sigs.k8s.io/release-utils/version.gitCommit=$(GIT_HASH) \
	-X sigs.k8s.io/release-utils/version.gitTreeState=clean \
	-X sigs.k8s.io/release-utils/version.buildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}}"

.if ${FLAVOR} == server
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.endif

GIT_HASH=	4118a64b4b9c228a968b2d935a00807ca1b33aed

.include <bsd.port.pre.mk>

# Bring DISTINFO_FILE into scope so we can get the timestamp.
SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rekor
.if ${FLAVOR} == client
	${INSTALL_DATA} ${WRKSRC}/config/rekor.yaml ${STAGEDIR}${PREFIX}/etc/rekor/rekor.yaml.sample
.elif ${FLAVOR} == server
	${INSTALL_DATA} ${WRKSRC}/rekor-server.yaml ${STAGEDIR}${PREFIX}/etc/rekor/rekor-server.yaml.sample
.endif

.include <bsd.port.post.mk>
