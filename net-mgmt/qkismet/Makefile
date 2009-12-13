# New ports collection makefile for:	qkismet
# Date created:		2009-11-12
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qkismet
PORTVERSION=	0.3.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/qKismet/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	This is graphical Kismet client writtent in Qt

RUN_DEPENDS=	kismet:${PORTSDIR}/net-mgmt/kismet

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build network

QMAKE_PRO=	${PORTNAME}.pro

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

do-patch:
	${REINPLACE_CMD} -e 's,:/img/,${DATADIR}/img/,g' \
	${WRKSRC}/*.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../build/release/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} img ${DATADIR}

.include <bsd.port.mk>
