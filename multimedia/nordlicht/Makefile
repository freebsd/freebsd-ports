# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	nordlicht
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	t@tobik.me
COMMENT=	Create moodbars from video files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpopt.so:devel/popt \
		libpng.so:graphics/png

USE_GITHUB=	yes

USES=		cmake:outsource pkgconfig
USE_LDCONFIG=	yes

BROKEN_aarch64=		Fails to install: runaway process
BROKEN_powerpc64=	Does not build

.include <bsd.port.mk>
