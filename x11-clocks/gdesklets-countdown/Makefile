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

WRKSRC=		${WRKDIR}/juju-countdown

NO_BUILD=	yes
USE_PYTHON=	yes

SUB_FILES=	pkg-message
SUB_LIST=	NAME="${NAME}"

DATADIR=	${PREFIX}/share/gdesklets
NAME=		Countdown

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/Displays/${NAME}
	@${MKDIR} ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/Sensors/${NAME}/*.py ${DATADIR}/Sensors/${NAME}
	@${MKDIR} ${DATADIR}/Sensors/LTVFontSelector
	${INSTALL_DATA} ${WRKSRC}/Sensors/LTVFontSelector/*.py ${DATADIR}/Sensors/LTVFontSelector
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/LTVFontSelector
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/LTVFontSelector
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
