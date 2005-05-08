# New ports collection makefile for:	PyTVGrab
# Date created:		Sun May  8 07:22:39 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TVGrab
PORTVERSION=	0.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pytvgrab
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${MASTER_SITE_SUBDIR}-lib-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A xmltv python library to write grabbers of tv scheduling collections

EXTRACT_DEPENDS=	${PYTHON_SITELIBDIR}/dateutil/__init__.py:${PORTSDIR}/devel/py-dateutil:extract

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

post-extract:
# use tz.py from devel/py-dateutil
	@${INSTALL_DATA} ${PY_DATEUTIL_WRKSRC}/dateutil/tz.py \
		${WRKSRC}/lib/timezone.py

.include <bsd.port.pre.mk>

PY_DATEUTIL_PORTDIR=${PORTSDIR}/devel/py-dateutil
PY_DATEUTIL_WRKSRC!=cd ${PY_DATEUTIL_PORTDIR} && ${MAKE} -V WRKSRC

.include <bsd.port.post.mk>
