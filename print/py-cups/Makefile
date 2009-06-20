# New ports collection makefile for:	py-cups
# Date created:		2008-03-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/print/py-cups/Makefile,v 1.1 2008/03/20 13:55:32 ahze Exp $

PORTNAME=	cups
PORTVERSION=	1.9.45
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	http://cyberelk.net/tim/data/pycups/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	CUPS bindings for Python

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-client

USE_PYTHON=	yes
USE_ICONV=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=	yes
CFLAGS+=	-I${LOCALBASE}/include -DVERSION=\\\"${PORTVERSION}\\\"
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
PYDISTUTILS_EGGINFO=${PORTNAME}-1.0-py${PYTHON_VER}.egg-info
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cups.so

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/cupsconnection.c

.include <bsd.port.mk>
