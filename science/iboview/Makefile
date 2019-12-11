# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iboview
PORTVERSION=	20150427
PORTREVISION=	20
CATEGORIES=	science
MASTER_SITES=	http://www.iboview.org/bin/
DISTNAME=	ibo-view.20150427

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Program for analyzing molecular electronic structure

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
RUN_DEPENDS=	boost-libs>=0:devel/boost-libs

ONLY_FOR_ARCHS=	amd64

USES=		blaslapack:openblas fortran gl qmake:outsource qt:5 tar:bz2
USE_GL=		gl glu
USE_QT=		buildtools_build core gui widgets opengl script svg

PLIST_FILES=	bin/iboview

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iboview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
