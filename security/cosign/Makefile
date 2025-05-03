PORTNAME=	cosign
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Signing OCI containers and other artifacts using Sigstore
WWW=		https://www.sigstore.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.23,modules
CPE_VENDOR=	sigstore

GO_MODULE=	github.com/sigstore/cosign/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-buildid= \
		-X sigs.k8s.io/release-utils/version.gitVersion=$(DISTVERSION) \
		-X sigs.k8s.io/release-utils/version.gitCommit=$(GIT_HASH) \
		-X sigs.k8s.io/release-utils/version.gitTreeState=clean \
		-X sigs.k8s.io/release-utils/version.buildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}}"

PLIST_FILES=	bin/${PORTNAME}

GIT_HASH=	38bb98697005cdc5c092f031594c0e45d039f4a0

.include <bsd.port.pre.mk>

# Bring DISTINFO_FILE into scope so we can get the timestamp.
SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

.include <bsd.port.post.mk>
