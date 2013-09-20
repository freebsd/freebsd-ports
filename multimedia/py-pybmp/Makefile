# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	pyBMP
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	multimedia python
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/ \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module to control beep-media-player

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GNOME=	glib12
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
post-extract:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${FILESDIR}/setup.cfg.port >> ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
