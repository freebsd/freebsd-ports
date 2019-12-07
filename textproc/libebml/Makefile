# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libebml
DISTVERSION=	1.3.10
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		cmake compiler:c++11-lang pathfix tar:bzip2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Matroska-Org

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
