PORTNAME=	clboss
# To build from an arbitrary git commit comment PORTVERSION and PORTREVISION (if present)
PORTVERSION=	0.13
DISTVERSIONPREFIX=	v
# and uncomment the following two lines (use for example -git-HEAD or -git-f8d8348c)
#PORTVERSION=	0
#PKGNAMESUFFIX=	-git-0673c50e7
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	The Core Lightning Node Manager
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

CXXFLAGS=	-Wno-deprecated-declarations

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
.if defined(PKGNAMESUFFIX)
GIT_COMMIT=	${PKGNAMESUFFIX:C/-git-//}
.else
GIT_COMMIT=	${DISTVERSIONPREFIX}${PORTVERSION}
.endif
GH_TUPLE=	ZmnSCPxj:clboss:${GIT_COMMIT}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/clboss

.include <bsd.port.mk>
