# $FreeBSD$

PORTNAME=	avidemux26
PORTVERSION=	${AVIDEMUX2_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-cli

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (cli)

LIB_DEPENDS=	libADM6avutil.so.52:${PORTSDIR}/multimedia/avidemux26

MASTERDIR=	${.CURDIR}/../avidemux26
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux/cli

CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"

post-configure: post-configure-common

.include <bsd.port.post.mk>
