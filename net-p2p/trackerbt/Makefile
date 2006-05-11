# New ports collection makefile for:	trackerbt
# Date created:		Sun Jan 16 03:28:23 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackerbt
PORTVERSION=	0.1.1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/trackerbt/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A BitTorrent tracker with additional distributed functionality

BUILD_DEPENDS=	${LOCALBASE}/lib/libSockets.a:${PORTSDIR}/net/Sockets

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_ICONV=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes
MAKE_ENV=	CXX="${CXX}"

# ssl support
CFLAGS+=	${PTHREAD_CFLAGS} -DHAVE_OPENSSL

PLIST_DIRS=	\
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		bin/${PORTNAME} \
		%%EXAMPLESDIR%%/config.xml

post-patch:
# CXX safeness
# CXXFLAGS safeness
# SSL include safeness
	@${REINPLACE_CMD} -E \
		-e 's|g\+\+|${CXX}|' \
		-e 's|^INCLUDE.+$$|INCLUDE=-I${OPENSSLINC} -I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2 -I${LOCALBASE}/include/Sockets|' \
		-e 's|^LIBS.+$$|LIBS=-L${OPENSSLLIB} ${PTHREAD_LIBS} -L${LOCALBASE}/lib \\|' \
		${BUILD_WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -E \
		-e 's|\(__sighandler_t\)||' \
		${WRKSRC}/tracker.cpp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/config.xml ${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE= FreeBSD prior to 500000 does not support uuid(3) required\
	for building
.endif

.include <bsd.port.post.mk>
