# New ports collection makefile for:    gdesklets-imapmail
# Date created:                		19 November 2003
# Whom:                    		Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	imapmail
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Displays new/total mail count from IMAP mailbox

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets \
		${DATADIR}/gdesklets/Sensors/IconButton/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_iconbutton

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes

NAME=		imapmail
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKDIR}/${PORTNAME} -name '*.bak' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/light-theme/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/dark-theme/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/
	@${INSTALL_DATA} ${WRKSRC}/dark-theme/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/gfx/
	@${INSTALL_DATA} ${WRKSRC}/light-theme/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/light-theme/
	@${INSTALL_DATA} ${WRKSRC}/light-theme/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/light-theme/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
