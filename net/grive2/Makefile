PORTNAME=	grive2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2-dev
PORTREVISION=	12
CATEGORIES=	net

MAINTAINER=	samuel@andersentech.net
COMMENT=	Open source client for Google Drive
WWW=		https://github.com/vitalif/grive2

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
GH_TAGNAME=	ffb744a

PLIST_FILES=	bin/grive \
		share/man/man1/grive.1.gz

OPTIONS_DEFINE=	BACKTRACE

BACKTRACE_DESC=	Enable backtrace support
BACKTRACE_LIB_DEPENDS=	libbfd.so:devel/binutils
BACKTRACE_LDFLAGS=	-lexecinfo
BACKTRACE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_BFD=true

.include <bsd.port.mk>
