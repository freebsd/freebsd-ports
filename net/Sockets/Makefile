# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sockets
PORTVERSION=	2.3.9.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.alhem.net/Sockets/ \
		https://www.netfence.it/Sockets/

MAINTAINER=	ml@netfence.it
COMMENT=	C++ wrapper for BSD-style sockets

USES+=		gmake ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

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
