# New ports collection makefile for:	py-spreadmodule
# Date created:		24 May 2002
# Whom:			Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	spreadmodule
PORTVERSION=	1.5
CATEGORIES=	net python
MASTER_SITES=	http://www.zope.org/Members/tim_one/spread/SpreadModule-1.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpreadModule-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python extension module for the Spread group communications package

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/spread.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	SpreadModule

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
