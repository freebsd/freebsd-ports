# $FreeBSD$

PORTNAME=	packer
PORTVERSION=	0.12.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for creating machine images

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

STRIP=		# stripping can break go binaries

# Make it so that post-extract runs before the GH_SUBDIR targets.
TARGET_ORDER_OVERRIDE=	680:post-extract

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
