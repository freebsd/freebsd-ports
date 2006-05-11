# New ports collection makefile for:	py-spreadmodule
# Date created:		24 May 2002
# Whom:			Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	spreadmodule
PORTVERSION=	1.4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYTHON}
MASTER_SITE_SUBDIR=other/spread
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpreadModule-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	joshua@roughtrade.net
COMMENT=	A python extension module for the Spread group communcations package

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/spread.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
