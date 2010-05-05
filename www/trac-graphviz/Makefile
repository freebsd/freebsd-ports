# New ports collection makefile for: trac-graphviz
# Date created:                      January 14, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:L}
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	www devel graphics python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	brooks@freebsd.org
COMMENT=	Graphviz pluging for Trac's wiki

RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts \
		dot:${PORTSDIR}/graphics/graphviz \
		tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	graphviz
WRKSRC=		${WRKDIR}/${PORTNAME}plugin
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    -e 's|%%PREFIX%%|${PREFIX}|' \
	    -e 's|%%OSMAJOR%%|${OSREL:C/\..*$//}|' \
	${WRKSRC}/graphviz/graphviz.py

do-build:
	@${DO_NADA}

.include <bsd.port.mk>
