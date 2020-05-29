# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycups
PORTVERSION=	1.9.74
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CUPS bindings for Python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libcups.so:print/cups

USES=		iconv localbase python tar:bzip2
USE_PYTHON=	autoplist concurrent distutils

# pycups 2.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^1\.

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(VERSION=\).*$$|\1${PORTVERSION}|' ${WRKSRC}/Makefile
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's| or sys.platform.startswith("freebsd"):|:|' ${WRKSRC}/setup.py
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cupsconnection.c
	@${REINPLACE_CMD} -e 's|#ifdef __SVR4|#ifdef __FreeBSD__|' ${WRKSRC}/cupsppd.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cups.so

.include <bsd.port.post.mk>
