# New ports collection makefile for:	chm2pdf
# Date created:				20 December 2007
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chm2pdf
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Python script that converts CHM files into PDF files

RUN_DEPENDS=	htmldoc:${PORTSDIR}/textproc/htmldoc \
		${PYTHON_SITELIBDIR}/chm/chm.py:${PORTSDIR}/textproc/pychm

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.9

PLIST_FILES=	bin/chm2pdf

.include <bsd.port.mk>
