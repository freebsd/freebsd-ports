# ex:ts=8
# Ports collection makefile for:	hashish
# Date Created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hashish
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Hashish-1.1

MAINTAINER=	jllovela@ncsu.edu
COMMENT=	GUI file and string hashing utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
LIB_DEPENDS=	wx_gtk-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/Hashish-1.1

.include <bsd.port.mk>
