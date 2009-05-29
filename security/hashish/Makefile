# ex:ts=8
# Ports collection makefile for:	hashish
# Date Created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hashish
PORTVERSION=	1.1a
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Hashish-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI file and string hashing utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

USE_WX=		2.4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
PLIST_FILES=	bin/hashish

BROKEN=		does not compile
DEPRECATED=		"${BROKEN}"
EXPIRATION_DATE=	2009-07-28

.include <bsd.port.mk>
