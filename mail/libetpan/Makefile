# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	0.32
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mail library

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_OPENSSL=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
