# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	cmark
PORTVERSION=	0.27.1
CATEGORIES=	textproc

MAINTAINER=	t@tobik.me
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	jgm

USES=		cmake:outsource python:3,test
USE_LDCONFIG=	yes

TEST_TARGET=	test

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
