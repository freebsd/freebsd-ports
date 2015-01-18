# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	bittorrent-libutp
PORTVERSION=	0.20130514
CATEGORIES=	net devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The uTorrent Transport Protocol library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:C/-.*//}
GH_PROJECT=	${PORTNAME:C/.*-//}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7c4f19a

USES=		dos2unix uidfix
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libutp

.include <bsd.port.mk>
