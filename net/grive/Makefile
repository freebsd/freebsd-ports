# Created by: ktsin@acm.org
# $FreeBSD$

PORTNAME=	grive
PORTVERSION=	0.2.0
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	ktsin@acm.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/binutils
LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs \
		curl:${PORTSDIR}/ftp/curl \
		expat:${PORTSDIR}/textproc/expat2 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		json:${PORTSDIR}/devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	Grive
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	93d696a
GH_TAGNAME=	v${PORTVERSION}

USES=		cmake
CXXFLAGS+=	-I${LOCALBASE}/include

MAKE_JOBS_UNSAFE=	yes

FETCH_ARGS=	-pRr

PLIST_FILES=	bin/grive
MAN1=		grive.1

.include <bsd.port.pre.mk>

# We need clang or GCC 4.6+ to build
# Piece of code copied from bsd.gecko.mk
.if ${CC} == "cc" && (exists(/usr/bin/clang) && ${OSVERSION} >= 900014)
CC=		/usr/bin/clang
.endif
.if ${CXX} == "c++" && (exists(/usr/bin/clang++) && ${OSVERSION} >= 900014)
CXX=		/usr/bin/clang++
.endif
.if ${CPP} == "cpp" && (exists(/usr/bin/clang-cpp) && ${OSVERSION} >= 900045)
CPP=		/usr/bin/clang-cpp
.endif
.if ${CC} != "cc" && ${CPP} == "cpp"
CPP=		${CC} -E
.endif
# fallback to gcc otherwise
.if ${CC} == "cc" || ${CXX} == "c++"
USE_GCC=	4.6+
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/grive

.include <bsd.port.post.mk>
