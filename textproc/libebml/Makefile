# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libebml
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML

LICENSE=	LGPL21

USES=		cmake pathfix tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Matroska-Org

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
