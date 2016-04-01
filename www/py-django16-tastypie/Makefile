# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-tastypie
PKGNAMESUFFIX=	16

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Create REST API for Django apps using Django 1.6

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}django16>0:www/py-django16

MASTERDIR=	${.CURDIR}/../py-django-tastypie

CONFLICTS_INSTALL=	 ${PKGNAMEPREFIX}${PORTNAME}

.include "${MASTERDIR}/Makefile"
