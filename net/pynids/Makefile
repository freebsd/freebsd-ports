# New ports collection makefile for:   pynids
# Date created:                22 Jun 2005
# Whom:                        Corey Smith
#
# $FreeBSD$
#

PORTNAME=	pynids
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	http://pilcrow.madison.wi.us/pynids/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pynids-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	corsmith@gmail.com
COMMENT=	Python interface to libnids

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

CFLAGS+=	-fPIC

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/nidsmodule.so

post-patch:
	${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	${CHMOD} a+rx ${WRKSRC}/config.guess
	${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	${CHMOD} a+rx ${WRKSRC}/config.sub

.include <bsd.port.mk>
