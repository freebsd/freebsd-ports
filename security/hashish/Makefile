# ex:ts=8
# Ports collection makefile for:	hashish
# Date Created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hashish
PORTVERSION=	1.1a
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Hashish-${PORTVERSION}

MAINTAINER=	jllovela@ncsu.edu
COMMENT=	GUI file and string hashing utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		WX_CONFIG="${X11BASE}/bin/wxgtk2-2.4-config"
USE_GMAKE=	yes
PLIST_FILES=	bin/hashish

.include <bsd.port.mk>
