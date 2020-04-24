# Created by: Vsevolod Lobko <seva@sevasoft.kiev.ua>
# $FreeBSD$

PORTNAME=	milter
PORTVERSION=	1.0.4
DISTVERSIONPREFIX=	${GH_PROJECT}-
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	estartu@augusta.de
COMMENT=	Python interface to Sendmail milter API

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	libmilter.so:mail/libmilter
CFLAGS+=	-I${LOCALBASE}/include
.endif

USES=	python

USE_GITHUB=	yes
GH_ACCOUNT=	sdgathman
GH_PROJECT=	py${PORTNAME}
USE_PYTHON=	distutils autoplist flavors

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/milter.so

.include <bsd.port.mk>
