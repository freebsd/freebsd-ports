# New ports collection makefile for:	fugu
# Date created:				11 August 2000
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	fugu
PORTVERSION=	0.9.9e
CATEGORIES=	net python
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	peterh@sapros.com

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python
RUN_DEPENDS+= 	${LOCALBASE}/lib/python1.5/site-packages/Pmw:${PORTSDIR}/x11-toolkits/pmw

PYTHON_VERSION=		python1.5
PYTHON_NO_DEPENDS=	yes
USE_XLIB=		yes
GNU_CONFIGURE=		yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" INSTALL=""
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
