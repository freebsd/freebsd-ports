# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatroska
PORTVERSION=	1.4.9
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extensible Multimedia Container Format

LICENSE=	LGPL21

LIB_DEPENDS=	libebml.so:textproc/libebml

USES=		cmake compiler:c++11-lang pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
