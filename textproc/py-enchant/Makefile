# New ports collection makefile for:	py-enchant
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	enchant
PORTVERSION=	1.1.5
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${MASTER_SITE_SUBDIR}-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A spellchecking library for Python based on the Enchant library

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant
BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_INSTALL_TARGET=	install_lib
PYDISTUTILS_INSTALLARGS=

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
