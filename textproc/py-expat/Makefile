# New ports collection makefile for:    py-expat
# Date created:         28 February 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	http://www.python.org/ftp/python/${PORTVERSION}/ \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${PYTHON_WRKSRC}/Modules

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
