# New ports collection makefile for:	iksemel
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	iksemel
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://jabberstudio.2nw.net/iksemel/

MAINTAINER=	trasz@freebsd.org
COMMENT=	XML parser library mainly designed for Jabber applications

LIB_DEPENDS=	gnutls.13:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool:15
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

INFO=	iksemel

.include <bsd.port.mk>
