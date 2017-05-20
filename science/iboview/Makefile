# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iboview
PORTVERSION=	20150427
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.iboview.org/bin/
DISTNAME=	ibo-view.20150427

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Program for analyzing molecular electronic structure

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	qt5-buildtools>=0:devel/qt5-buildtools \
		boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libgcc_s.so:lang/gcc
RUN_DEPENDS=	boost-libs>=0:devel/boost-libs

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only builds and is supported on amd64

USES=		tar:bz2 qmake:outsource blaslapack:openblas
USE_GL=		gl glu
USE_QT5=	core gui widgets opengl script svg

PLIST_FILES=	bin/iboview

post-patch:
	${REINPLACE_CMD} -e 's|%%_GCC_RUNTIME%%|${LOCALBASE}/lib/gcc${GCC_DEFAULT}|g' \
		${WRKSRC}/main.pro

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iboview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
