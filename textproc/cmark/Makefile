# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	cmark
PORTVERSION=	0.28.0
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource python:3,test
USE_GITHUB=	yes
GH_ACCOUNT=	commonmark
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}
TEST_TARGET=	test

.include <bsd.port.mk>
