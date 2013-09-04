# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	1.9.63
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CUPS bindings for Python

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups-client

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USES=		iconv
USE_PYDISTUTILS=	yes
USE_PYTHON=	-2.7

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/cups.so
PYDISTUTILS_EGGINFO=	py${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(VERSION=\).*$$|\1${PORTVERSION}|' ${WRKSRC}/Makefile
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's| or sys.platform.startswith("freebsd"):|:|' ${WRKSRC}/setup.py
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cupsconnection.c
	@${REINPLACE_CMD} -e 's|#ifdef __SVR4|#ifdef __FreeBSD__|' ${WRKSRC}/cupsppd.c

.include <bsd.port.post.mk>
