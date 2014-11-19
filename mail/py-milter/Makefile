# Created by: Vsevolod Lobko <seva@sevasoft.kiev.ua>
# $FreeBSD$

PORTNAME=	milter
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PYPORTNAME}/${PYPORTNAME}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYPORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to Sendmail milter API

LICENSE=	GPLv2

.if !exists(/usr/lib/libmilter.so)
LIB_DEPENDS=	libmilter.so:${PORTSDIR}/mail/sendmail
.endif

PYPORTNAME=	${PKGNAMEPREFIX:C/[0-9]+-//}${PORTNAME}

DIST_SUBDIR=	python
USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
