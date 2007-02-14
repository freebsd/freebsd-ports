# New ports collection makefile for:	apache-xml-security-c
# Date created:				06 Febuary 2007
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	xml-security-c
PORTVERSION=	1.3.1
CATEGORIES=	security
MASTER_SITES=	http://xml.apache.org/security/dist/c-library/
PKGNAMEPREFIX=	apache-

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Apache XML security libraries C version

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
