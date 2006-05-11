# New ports collection makefile for:	minder
# Date created:		Sun Jan 16 01:16:28 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minder
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/minder/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A small network application for automatic maintenance of peer lists

BUILD_DEPENDS=	${LOCALBASE}/lib/libSockets.a:${PORTSDIR}/net/Sockets

USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes
MAKE_ENV=	CXX="${CXX}"

# ssl support
CFLAGS+=	${PTHREAD_CFLAGS} -DHAVE_OPENSSL

PLIST_DIRS=	\
		%%EXAMPLESDIR%%
PLIST_FILES=	\
		%%EXAMPLESDIR%%/minder.cfg \
		bin/${PORTNAME}

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE= FreeBSD prior to 500000 does not support uuid(3) required\
	for building
.endif

.include <bsd.port.post.mk>
