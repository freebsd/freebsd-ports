# $FreeBSD$

PORTNAME=	minio
PORTVERSION=	2016.10.24.21.23.47
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

BUILD_DEPENDS=	go>=1.6:lang/go \
		bash:shells/bash

USES=		gmake

USE_GITHUB=	yes
GH_TAGNAME=	RELEASE.2016-10-24T21-23-47Z
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go

STRIP=		# stripping can break go binaries
PLIST_FILES=	bin/minio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
