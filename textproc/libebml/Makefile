# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libebml
DISTVERSION=	1.4.2
CATEGORIES=	textproc
MASTER_SITES=	https://dl.matroska.org/downloads/libebml/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		cmake compiler:c++11-lang tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
