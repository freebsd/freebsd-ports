# New ports collection makefile for:	iksemel
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	iksemel
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	markocpc@gmail.com
COMMENT=	XML parser library mainly designed for Jabber applications

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

INFO=	iksemel

.include <bsd.port.mk>
