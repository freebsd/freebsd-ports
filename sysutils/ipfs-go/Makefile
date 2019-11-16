# $FreeBSD$

PORTNAME=	ipfs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.21
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ipfs/go-ipfs/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-go
DISTNAME=	go-ipfs-source

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	IPFS implementation in Go

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

ONLY_FOR_ARCHS=	amd64 i386

USES=		go:modules

GO_TARGET=	./cmd/ipfs:ipfs-go

NO_WRKSUBDIR=	yes

USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	${FULLNAME}
SUB_LIST=	IPFS_USER=${IPFS_USER} \
		IPFS_GROUP=${IPFS_GROUP} \
		IPFS_HOME=${IPFS_HOME}
PLIST_SUB=	IPFS_USER=${IPFS_USER} \
		IPFS_GROUP=${IPFS_GROUP} \
		IPFS_HOME=${IPFS_HOME}

IPFS_USER?=	${FULLNAME}
IPFS_GROUP?=	${FULLNAME}
IPFS_HOME?=	/var/db/${FULLNAME}

USERS=		${IPFS_USER}
GROUPS=		${IPFS_GROUP}

FULLNAME=	${PORTNAME}${PKGNAMESUFFIX}

# unbreak vendored golang.org/x/xerrors with go1.13
# can be removed after vendor/golang.org/x/xerrors is updated to a985d3407aa7 or later
post-patch:
	@${RM} ${WRKSRC}/vendor/golang.org/x/xerrors/adaptor_go1_13.go
	@${RM} ${WRKSRC}/vendor/golang.org/x/xerrors/format_go1_13.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/adaptor_go1_12.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/format_go1_12.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/frame_go1_12.go

post-install:
	@${MKDIR} ${STAGEDIR}${IPFS_HOME}

.include <bsd.port.mk>
