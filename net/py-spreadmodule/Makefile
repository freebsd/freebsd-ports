# Created by: Joshua Goodall <joshua@roughtrade.net>
# $FreeBSD$

PORTNAME=	spreadmodule
PORTVERSION=	1.5
CATEGORIES=	net python
MASTER_SITES=	http://www.zope.org/Members/tim_one/spread/SpreadModule-1.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpreadModule-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python extension module for the Spread group communications package

DEPRECATED=	Depends on expired net/spread
EXPIRATION_DATE=2014-05-01

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/spread.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	SpreadModule

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
