# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	0.26
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		db3.3:${PORTSDIR}/databases/db3

USE_OPENSSL=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db3 -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -ldb3"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
