# Created by: Carlos J Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grive2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1-dev
PORTREVISION=	5
CATEGORIES=	net

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libyajl.so:devel/yajl

USES=		cmake compiler:c++11-lang localbase pkgconfig
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

USE_GITHUB=	yes
GH_ACCOUNT=	vitalif
GH_TAGNAME=	ad9b66a

PLIST_FILES=	bin/grive \
		man/man1/grive.1.gz

OPTIONS_DEFINE=	BACKTRACE

BACKTRACE_DESC=	Enable backtrace support
BACKTRACE_LIB_DEPENDS=	libbfd.so:devel/libbfd
BACKTRACE_LDFLAGS=	-lexecinfo
BACKTRACE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_BFD=true

.include <bsd.port.mk>
