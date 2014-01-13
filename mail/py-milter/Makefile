# Created by: Vsevolod Lobko <seva@sevasoft.kiev.ua>
# $FreeBSD$

PORTNAME=	milter
PORTVERSION=	0.9.7
CATEGORIES=	mail python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PYPORTNAME}/${PYPORTNAME}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYPORTNAME}-${PORTVERSION}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Python interface to Sendmail milter API

LICENSE=	GPLv2

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	milter:${PORTSDIR}/mail/sendmail
.endif

PYPORTNAME=	${PKGNAMEPREFIX:C/[0-9]+-//}${PORTNAME}

DIST_SUBDIR=	python
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PYPORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
