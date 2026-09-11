PORTNAME=	cmark-gfm
DISTVERSION=	0.29.0.gfm.13
CATEGORIES=	textproc

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Extended version of the C reference implementation of CommonMark
WWW=		https://github.com/github/cmark-gfm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing pathfix python:test

USE_GITHUB=	yes
GH_ACCOUNT=	github

USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
PLIST_SUB=	VERSION=${DISTVERSION}

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/registry.h ${WRKSRC}/src/plugin.h \
		${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
