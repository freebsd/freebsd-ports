# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	wikitemplates
PORTVERSION=	0.3.0p3
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION:S/p/rc/}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Templates for the Trac wiki

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac
#		${PYTHON_SITELIBDIR}/TracCtxtnavAdd-2.0-py${PYTHON_VER}.egg:www/trac-ctxtnavadd

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
