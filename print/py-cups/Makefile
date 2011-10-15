# New ports collection makefile for:	py-cups
# Date created:		2008-03-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.9.60
CATEGORIES=	print python
MASTER_SITES=	http://cyberelk.net/tim/data/pycups/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CUPS bindings for Python

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-client

CFLAGS+=	-I${LOCALBASE}/include -DVERSION=\\\"${PORTVERSION}\\\"
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
USE_BZIP2=	yes
USE_ICONV=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON=	-2.7

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cups.so
PYDISTUTILS_EGGINFO=py${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/cupsconnection.c
	@${REINPLACE_CMD} -e 's|#ifdef __SVR4|#ifdef __FreeBSD__|' ${WRKSRC}/cupsppd.c

.include <bsd.port.mk>
