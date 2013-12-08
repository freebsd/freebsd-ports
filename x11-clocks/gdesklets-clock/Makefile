# $FreeBSD$

PORTNAME=	clock
PORTVERSION=	0.32
PORTREVISION=	14
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	clock-desklet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Various clock displays for Gnome 2.x

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_PYTHON=	2

SUB_FILES=	pkg-message
SUB_LIST=	NAME="${NAME}"

DATADIR=	${PREFIX}/share/gdesklets
NAME=		Clock

LANG=		de fr pt sq sr sr@Latn sv

NO_STAGE=	yes
do-build:
	@${PYTHON_CMD} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} ${WRKSRC}/Clock/__init__.py < ${FILESDIR}/Clock::__init__.py

do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/Displays/${NAME}
	@${MKDIR} ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/*.xcf ${DATADIR}/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.dat ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/Sensors/${NAME}
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
.endfor
	@${LN} -s ${DATADIR}/Displays/${NAME}/README \
		${DATADIR}/Sensors/${NAME}/README
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
