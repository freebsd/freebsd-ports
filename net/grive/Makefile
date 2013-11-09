# Created by: Key-Teck SIN <ktsin@acm.org>
# $FreeBSD$

PORTNAME=	grive
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	ktsin@acm.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/binutils
LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libjson.so:${PORTSDIR}/devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	Grive
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	93d696a
GH_TAGNAME=	v${PORTVERSION}

USES=		cmake
CXXFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/grive man/man1/grive.1.gz

# Allow to build with GCC 4.2
post-patch:
	@${REINPLACE_CMD} -e 's,log::,gr::&,g' ${WRKSRC}/grive/src/main.cc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grive

.include <bsd.port.mk>
