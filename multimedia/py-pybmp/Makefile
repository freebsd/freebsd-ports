# New ports collection makefile for:	py-pybmp
# Date created:		2006-04-30
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	pyBMP
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://dev-1.borgforge.net/pyBMP/chrome/site/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module to control beep-media-player

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GNOME=	glib12
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-extract:
	${SED} -e 's|%%X11BASE%%|${X11BASE}|g' ${FILESDIR}/setup.cfg.port >> ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
