# $FreeBSD$

PORTNAME=	ipfs-go
PORTVERSION=	0.3.10
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	IPFS implementation in Go

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

BROKEN_i386=	does not build

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ipfs
GH_PROJECT=	go-ipfs
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

MAKE_ENV+=	GOPATH=${WRKSRC}

PLIST_FILES=	bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

STRIP=		# stripping can break go binaries

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-32bit
.endif

post-patch:
	${GREP} -lR github.com/ipfs/go-ipfs/vendor/QmQg1J6vikuXF9oDvm4wpdeAUvvkVEKW1EYDw9HhTMnP2b/go-log ${WRKSRC} 2>/dev/null | \
	 while read gosrc; do sed -i.bak 's#github.com/ipfs/go-ipfs/vendor/##g' $$gosrc; done

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/ipfs/ipfs ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
