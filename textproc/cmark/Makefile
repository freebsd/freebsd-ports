# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	cmark
PORTVERSION=	0.26.1
CATEGORIES=	textproc

MAINTAINER=	t@tobik.me
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	python3:lang/python3

TEST_TARGET=	test

USE_GITHUB=	yes
GH_ACCOUNT=	jgm

USES=		cmake:outsource
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
