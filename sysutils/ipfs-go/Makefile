# $FreeBSD$

PORTNAME=	ipfs-go
PORTVERSION=	0.3.10
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	IPFS implementation in Go

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ipfs
GH_PROJECT=	go-ipfs

MAKE_ENV+=	GOPATH=${WRKSRC}

PLIST_FILES=	bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

STRIP=		# stripping can break go binaries

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-32bit
.endif

# Prepare for possible extra modules in future
post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.for src in CHANGELOG.md Dockerfile Godeps LICENSE Makefile README.md assets bin blocks blockservice circle.yml cmd commands contribute.md core dev.md diagnostics doc.go docs exchange fuse importer ipnsfs merkledag metrics misc namesys notifications p2p package.json path pin repo routing tar test thirdparty tour unixfs updates util vendor
	${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor

post-patch:
	${GREP} -R github.com/ipfs/go-ipfs/vendor/QmQg1J6vikuXF9oDvm4wpdeAUvvkVEKW1EYDw9HhTMnP2b/go-log ${WRKSRC} 2>/dev/null | \
	 cut -d':' -f1 | \
	 while read gosrc; do sed -i.bak 's#github.com/ipfs/go-ipfs/vendor/##g' $$gosrc; done

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/ipfs/ipfs ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
