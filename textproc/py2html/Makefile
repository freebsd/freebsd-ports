# New ports collection makefile for:	py2html
# Date created:				15 Nov 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	py2html
PORTVERSION=	0.7
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	-${PYTHON_PKGNAMEPREFIX:S/-//}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Highlighter for HTML

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
MAKE_ENV=	PORTSDIR=${PORTSDIR}

.include <bsd.port.mk>
