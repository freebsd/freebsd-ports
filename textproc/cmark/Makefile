PORTNAME=	cmark
DISTVERSION=	0.31.1
CATEGORIES=	textproc

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	CommonMark parsing and rendering library and program in C
WWW=		https://github.com/commonmark/cmark

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing pathfix python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	commonmark

PLIST_SUB=	VERSION=${DISTVERSION}

CMAKE_OFF=	BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
