# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	wikitemplates
PORTVERSION=	0.3.0p3
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION:S/p/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Templates for the Trac wiki

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
#		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-2.0-py${PYTHON_VER}.egg:${PORTSDIR}/www/trac-ctxtnavadd

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
