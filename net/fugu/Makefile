# New ports collection makefile for:	fugu
# Date created:				11 August 2000
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	fugu
PORTVERSION=	1.1.8
CATEGORIES=	net python
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	peterh@sapros.com

RUN_DEPENDS+= 	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/pmw

USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" INSTALL=""
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
