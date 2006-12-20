# Ports collection makefile for:	py-openid
# Date created:				Dec 19, 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openid
PORTVERSION=	1.2.0
CATEGORIES=	security python
MASTER_SITES=	http://www.openidenabled.com/resources/downloads/python-openid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Python OpenID version

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/urljr:${PORTSDIR}/www/py-urljr \
		${PYTHON_SITELIBDIR}/yadis:${PORTSDIR}/net/py-yadis

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
