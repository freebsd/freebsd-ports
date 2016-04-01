# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sockets
PORTVERSION=	2.3.9.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.alhem.net/Sockets/ \
		http://www.netfence.it/Sockets/

MAINTAINER=	ml@netfence.it
COMMENT=	C++ wrapper for BSD-style sockets

#execinfo is optional and currently not configured (would need to patch source's #ifdef LINUX)
#LIB_DEPENDS=	execinfo.1:devel/libexecinfo

#Not needed without execinfo or xml
#CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib

USES+=		gmake
USE_GNOME=	libxml2
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
