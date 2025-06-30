PORTNAME=	minder
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/minder/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small network application for automatic maintenance of peer lists
WWW=		https://www.alhem.net/project/minder/index.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libSockets.so:net/Sockets

USES=		gmake gnome pkgconfig ssl
USE_CXXSTD=	c++14
USE_GNOME=	libxml2

CFLAGS+=	-DHAVE_OPENSSL
CPPFLAGS+=	$$(pkg-config --cflags libxml-2.0) \
		-I${LOCALBASE}/include/Sockets -I${LOCALBASE}/include
LDFLAGS+=	$$(pkg-config --libs libxml-2.0) \
		-L${LOCALBASE}/lib

PORTEXAMPLES=	minder.cfg
PLIST_FILES=	bin/minder

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS|#CFLAGS| ; \
		 s|^CPPFLAGS =|CPPFLAGS +=| ; \
		 s|-L/usr/local/lib|$$(LDFLAGS)| ; \
		 s|-luuid|| ; \
		 s|-lpthread|-pthread| ; \
		 s|g++|$$(CXX)|' ${BUILD_WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e \
		's|(__sighandler_t)||' ${WRKSRC}/minder.cpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} minder \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${FILESDIR} && ${INSTALL_DATA} minder.cfg.sample \
		${STAGEDIR}${EXAMPLESDIR}/minder.cfg)

.include <bsd.port.mk>
