# Ports collection makefile for:  libunpipc
# Version required:		1.0
# Date created:			Sept 28, 1999
# Whom:				james@targetnet.com
#
# $FreeBSD$
#

DISTNAME=	unpv22e
PKGNAME=	libunpipc-1.0
CATEGORIES=     net
MASTER_SITES=	ftp://ftp.kohala.com/pub/rstevens/ \
		http://compass.net.edu.cn:8000/programming/

MAINTAINER=	james@targetnet.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-configure:
	ln -s ${WRKSRC}/config.h ${WRKSRC}/unpipc_config.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libunpipc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/unpipc.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/config.h ${PREFIX}/include/unpipc_config.h

.include <bsd.port.post.mk>
