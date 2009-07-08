# New ports collection makefile for:    py-mpz
# Date created:         18 Oct 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpz
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python bindings to the GNU Multiple Precision library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/mpz.so
DIST_SUBDIR=	python
USE_PYTHON=	-2.3
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=	0.0.0
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
