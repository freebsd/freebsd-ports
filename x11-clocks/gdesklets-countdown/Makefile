# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	countdown
PORTVERSION=	0.8
PORTREVISION=	14
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	juju-countdown-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Countdown the remaining time until a configurable date

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/juju-countdown

USES=		python

SUB_FILES=	pkg-message
SUB_LIST=	NAME="${NAME}"

DATADIR=	${PREFIX}/share/gdesklets
NAME=		Countdown

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Displays/${NAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} README *.display \
		${STAGEDIR}${DATADIR}/Displays/${NAME})
	@${MKDIR} ${STAGEDIR}${DATADIR}/Displays/${NAME}/gfx
	(cd ${WRKSRC}/gfx && ${INSTALL_DATA} *.png \
		${STAGEDIR}${DATADIR}/Displays/${NAME}/gfx)
	@${MKDIR} ${STAGEDIR}${DATADIR}/Sensors/${NAME}
	(cd ${WRKSRC}/Sensors/${NAME} && ${INSTALL_DATA} *.py \
		${STAGEDIR}${DATADIR}/Sensors/${NAME})
	@${MKDIR} ${STAGEDIR}${DATADIR}/Sensors/LTVFontSelector
	(cd ${WRKSRC}/Sensors/LTVFontSelector && ${INSTALL_DATA} *.py \
		${STAGEDIR}${DATADIR}/Sensors/LTVFontSelector)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${DATADIR} -f ${DATADIR_REL})
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${DATADIR} -f ${DATADIR_REL})

.include <bsd.port.mk>
