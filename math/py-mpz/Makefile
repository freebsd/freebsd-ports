# New ports collection makefile for:    py-mpz
# Date created:         18 Oct 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpz
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYTHON}
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python bindings to the GNU Multiple Precision library

LIB_DEPENDS=	gmp.3:${PORTSDIR}/math/libgmp-freebsd

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules
MD5_FILE=	${PORTSDIR}/lang/python/distinfo

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
