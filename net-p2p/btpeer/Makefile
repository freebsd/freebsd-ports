# New ports collection makefile for:	btpeer
# Date created:		Sun Sep 25 13:54:22 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	btpeer
PORTVERSION=	0.2.1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.alhem.net/project/btpeer/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Client functionality of bittorrent protocol, network only environment

BUILD_DEPENDS=	${LOCALBASE}/lib/libSockets-devel.a:${PORTSDIR}/net/Sockets-devel

USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes

# ssl support
CFLAGS+=	${PTHREAD_CFLAGS} -DHAVE_OPENSSL

PROGRAM_FILES=	\
		inject \
		newpeer

post-patch:
# CXX safeness
# CXXFLAGS safeness
# SSL include safeness
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|^INCLUDE.+$$|INCLUDE=-I${OPENSSLINC} -I${LOCALBASE}/include/Sockets-devel|' \
		-e 's|^LIBS.+$$|LIBS=-L${OPENSSLLIB} ${PTHREAD_LIBS} -L${LOCALBASE}/lib \\|' \
		${BUILD_WRKSRC}/${MAKEFILE}

.for f in ${PROGRAM_FILES}
PLIST_FILES+=	bin/${PORTNAME}-${f}
.endfor

do-install:
.for f in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/${PORTNAME}-${f}
.endfor

.include <bsd.port.mk>
