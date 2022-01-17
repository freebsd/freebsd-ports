PORTNAME=	cmark
DISTVERSION=	0.30.2
CATEGORIES=	textproc

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake python:3.4+,test
USE_GITHUB=	yes
GH_ACCOUNT=	commonmark
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	 py*-CommonMark # bin/cmark

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING="lib"
PLIST_SUB=	VERSION=${PORTVERSION}
TEST_TARGET=	test

.include <bsd.port.mk>
