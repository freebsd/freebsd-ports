# $FreeBSD$

PORTNAME=	rclone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.43
CATEGORIES=	net

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Sync files to and from various cloud services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	ncw
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

PLIST_FILES=	bin/rclone

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
