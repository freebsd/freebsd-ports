# New ports collection makefile for:	libssh
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libssh
PORTVERSION=	0.3.4
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh.org/files/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A library implementing the SSH1 and SSH2 protocol

MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}
CONFIGURE_WRKSRC=	${CMAKE_SOURCE_PATH}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

post-patch:
	@${MKDIR} ${WRKSRC}/build
	@${RM} ${WRKSRC}/cmake/Modules/UseDoxygen.cmake

.include <bsd.port.mk>
