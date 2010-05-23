# New ports collection makefile for:    py-expat
# Date created:         28 February 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to the Expat XML parser

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

DIST_SUBDIR=	python
PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/pyexpat.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pyexpat
PYDISTUTILS_PKGVERSION=	0.0.0
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
