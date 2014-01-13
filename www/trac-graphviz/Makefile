# $FreeBSD$

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:L}
PORTVERSION=	0.7.4
PORTREVISION=	6
CATEGORIES=	www devel graphics python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphviz plugin for Trac's wiki

RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts \
		dot:${PORTSDIR}/graphics/graphviz \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	graphviz
WRKSRC=			${WRKDIR}/${PORTNAME}plugin
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    -e 's|%%PREFIX%%|${PREFIX}|' \
	    -e 's|%%OSMAJOR%%|${OSREL:C/\..*$//}|' \
	${WRKSRC}/graphviz/graphviz.py

.include <bsd.port.mk>
