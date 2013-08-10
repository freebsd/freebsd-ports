# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	libcmime
PORTVERSION=	0.1.7
CATEGORIES=	mail
MASTER_SITES=	http://www.libcmime.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	Lightweight C mime library

LICENSE=	LGPL3

BUILD_DEPENDS=	bison>=1.8:${PORTSDIR}/devel/bison \
		flex>=2.5.33:${PORTSDIR}/textproc/flex

USES=		cmake pkgconfig
CMAKE_ARGS+=	--no-warn-unused-cli -DCMAKE_PREFIX_PATH:PATH=${LOCALBASE}

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG DOCS

PORTDOCS=	AUTHORS CHANGELOG INSTALL README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|\$${LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
