# $FreeBSD$

PORTNAME=	restic
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Restic backup program

LICENSE=	BSD2CLAUSE

USES=		go
USE_GITHUB=	yes

STRIP=		# stripping can break go binaries
PLIST_FILES=	bin/restic

do-build:
	@(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run build.go)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
