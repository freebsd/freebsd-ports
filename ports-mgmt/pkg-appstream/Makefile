PORTNAME=	pkg-appstream
DISTVERSIONPREFIX=	v
PORTVERSION=	1.0.0
CATEGORIES=	ports-mgmt

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Pkg plugin for downloading AppStream metadata
WWW=		https://github.com/freebsd/pkg-appstream

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/pkg.h:ports-mgmt/pkg

USES=		localbase

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

MAKE_ENV=	LIBOWN=nobody LIBGRP=nobody

PLIST_FILES=	lib/pkg/appstream.so

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pkg

.include <bsd.port.mk>
