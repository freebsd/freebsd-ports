# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minder
PORTVERSION=	2.0.2
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/minder/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small network application for automatic maintenance of peer lists

BROKEN=		Fails to link

BUILD_DEPENDS=	${LOCALBASE}/lib/libSockets.a:${PORTSDIR}/net/Sockets

USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes

# ssl support
CFLAGS+=	${PTHREAD_CFLAGS} -DHAVE_OPENSSL

PLIST_DIRS=	\
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		%%EXAMPLESDIR%%/minder.cfg \
		bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
# CXX safeness
# CXXFLAGS safeness
# SSL include safeness
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|^INCLUDE.+$$|INCLUDE=-I${OPENSSLINC} -I${LOCALBASE}/include/Sockets|' \
		-e 's|^LIBS.+$$|LIBS=-L${OPENSSLLIB} ${PTHREAD_LIBS} -L${LOCALBASE}/lib \\|' \
		${BUILD_WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -E \
		-e 's|\(__sighandler_t\)||' \
		${WRKSRC}/minder.cpp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/minder.cfg.sample \
		${EXAMPLESDIR}/minder.cfg

.include <bsd.port.mk>
