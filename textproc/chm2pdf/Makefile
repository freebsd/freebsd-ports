# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chm2pdf
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Python script that converts CHM files into PDF files

LICENSE=	GPLv2

RUN_DEPENDS=	htmldoc:textproc/htmldoc \
		${PYTHON_SITELIBDIR}/chm/chm.py:textproc/pychm

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	0.9

PLIST_FILES=	bin/chm2pdf

.include <bsd.port.mk>
