# New ports collection makefile for:   C++ Sockets
# Date created:                Tue Jun 29 16:00:00 UTC 2010
# Whom:                 Andrea Venturoli <ml@netfence.it>
#
# $FreeBSD$
#

PORTNAME=	Sockets
PORTVERSION=	2.3.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.alhem.net/Sockets/ \
		http://www.netfence.it/Sockets/

MAINTAINER=	ml@netfence.it
COMMENT=	A C++ wrapper for BSD-style sockets

#execinfo is optional and currently not configured (would need to patch source's #ifdef LINUX)
#LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

#Not needed without execinfo or xml
#CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_SAFE=yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

ALL_TARGET=	all shared
INSTALL_TARGET=	install_shared

post-patch:
# PREFIX safeness
	@${CP} ${PATCHDIR}/Makefile.Defines.freebsd ${WRKSRC}
	@${REINPLACE_CMD} -E \
		-e 's|linux-x86-32|freebsd|' \
		-e 's|^PREFIX.+$$|PREFIX=${PREFIX}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
