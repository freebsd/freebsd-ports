# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minder
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/minder/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small network application for automatic maintenance of peer lists

LICENSE=	GPLv2+

LIB_DEPENDS=	libSockets.so:net/Sockets

USES=		gmake pkgconfig
USE_GNOME=	libxml2
USE_OPENSSL=	yes

CFLAGS+=	-DHAVE_OPENSSL
CPPFLAGS+=	$$(pkg-config --cflags libxml-2.0) \
		-I${LOCALBASE}/include/Sockets -I${LOCALBASE}/include
LDFLAGS+=	$$(pkg-config --libs libxml-2.0) \
		-L${LOCALBASE}/lib

PORTEXAMPLES=	minder.cfg
PLIST_FILES=	bin/minder

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
