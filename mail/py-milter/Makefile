# Created by: Vsevolod Lobko <seva@sevasoft.kiev.ua>
# $FreeBSD$

PORTNAME=	milter
PORTVERSION=	1.0.2
CATEGORIES=	mail python
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYPORTNAME}-${PORTVERSION}

MAINTAINER=	estartu@augusta.de
COMMENT=	Python interface to Sendmail milter API

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	libmilter.so:mail/libmilter
CFLAGS+=	-I${LOCALBASE}/include
.endif

PYPORTNAME=	${PKGNAMEPREFIX:C/[0-9]+-//}${PORTNAME}
GH_ACCOUNT=	sdgathman
GH_PROJECT=	${PYPORTNAME}
GH_TAGNAME=	${GH_PROJECT}-${PORTVERSION}

USES=	python

USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist flavors

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/milter.so

.include <bsd.port.pre.mk>

.if ${FLAVOR:Upy27:Mpy3*}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-miltermodule.c
.endif

.include <bsd.port.post.mk>
