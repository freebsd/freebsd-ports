# Ports collection makefile for:  libunpipc
# Date created:			Sept 28, 1999
# Whom:				james@targetnet.com
#
# $FreeBSD$
#

PORTNAME=	libunpipc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kohala.com/pub/rstevens/ \
		http://compass.net.edu.cn:8000/programming/
DISTNAME=	unpv22e

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The networking library used in UNIX Network Programming Volume 2 2e

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-configure:
	${LN} -s ${WRKSRC}/config.h ${WRKSRC}/unpipc_config.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libunpipc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/unpipc.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/config.h ${PREFIX}/include/unpipc_config.h

.include <bsd.port.post.mk>
