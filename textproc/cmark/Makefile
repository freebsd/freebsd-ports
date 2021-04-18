PORTNAME=	cmark
DISTVERSION=	0.29.0
CATEGORIES=	textproc

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	py[2-3][0-9]-CommonMark

USES=		cmake python:3.4+,test
USE_GITHUB=	yes
GH_ACCOUNT=	commonmark
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING="lib"
PLIST_SUB=	VERSION=${PORTVERSION}
TEST_TARGET=	test

.include <bsd.port.mk>
