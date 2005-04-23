# New ports collection makefile for:    gdesklets-enhallmail
# Date created:                		5 September 2004
# Whom:                    		Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	enhallmail
PORTVERSION=	0.3
CATEGORIES=	mail gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/ \
		http://www.mathematik.uni-marburg.de/~wetzmj/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	LT${PORTNAME}-${PORTVERSION}

MAINTAINER=	radek@raadradd.com
COMMENT=	LT "enhanced" allmail, including IMAP and notification support

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${DATADIR}/gdesklets/Sensors/IconButton/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_iconbutton \
		${DATADIR}/gdesklets/Sensors/LTVBorder/__init__.py:${PORTSDIR}/deskutils/gdesklets-ltvariations

USE_X_PREFIX=	yes
USE_PYTHON=	yes

DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/LT${PORTNAME}

do-build:
	@${WRKSRC}/Install_${PORTNAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/bg
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/gfx/bg/*.png ${DATADIR}/gdesklets/Displays/${PORTNAME}/gfx/bg/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.py ${DATADIR}/gdesklets/Sensors/${PORTNAME}/

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${PORTNAME}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' < ${PKGMESSAGE}

.include <bsd.port.mk>
