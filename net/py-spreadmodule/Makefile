# New ports collection makefile for:	py-spreadmodule
# Date created:		24 May 2002
# Whom:			Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	spreadmodule
PORTVERSION=	1.2
CATEGORIES=	net python
MASTER_SITES=	http://www.python.org/other/spread/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpreadModule-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	joshua@roughtrade.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libsp.a:${PORTSDIR}/net/spread

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${PERL} -pi -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
