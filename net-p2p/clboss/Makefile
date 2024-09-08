PORTNAME=	clboss
DISTVERSIONPREFIX=	v
# To build from an arbitrary git commit comment DISTVERSION
DISTVERSION=	0.13.3
# and uncomment the following two lines (use for example -gf8d8348c where f8d8348c is a commit hash)
#DISTVERSION=	0
#DISTVERSIONSUFFIX=	-g0673c50e7
CATEGORIES=	net-p2p finance
.if defined(DISTVERSIONSUFFIX)
PKGNAMESUFFIX=	-devel
.endif

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Core Lightning Node Manager
WWW=		https://github.com/ZmnSCPxj/clboss

LICENSE=	MIT

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev
RUN_DEPENDS=	lightningd:net-p2p/c-lightning

USES=		autoreconf \
		compiler:c11 \
		gmake \
		libtool \
		pkgconfig \
		sqlite:3

CXXFLAGS+=	-Wno-deprecated-declarations

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ZmnSCPxj

SUB_FILES=	pkg-message
PLIST_FILES=	bin/clboss

.include <bsd.port.mk>
