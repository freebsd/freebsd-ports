# Created by: Key-Teck SIN <ktsin@acm.org>
# $FreeBSD$

PORTNAME=	grive
PORTVERSION=	0.2.0
CATEGORIES=	net

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

PLIST_FILES=	bin/grive
MAN1=		grive.1

# Allow to build with GCC 4.2
post-patch:
	@${REINPLACE_CMD} -e 's,log::,gr::&,g' ${WRKSRC}/grive/src/main.cc

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/grive

.include <bsd.port.mk>
