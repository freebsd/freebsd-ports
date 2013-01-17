# New ports collection makefile for:	easypbi
# Date created:			  	2011-11-29
# Whom:					jessefrgsmith@yahoo.ca
#
# $FreeBSD$
#

PORTNAME=	easypbi
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/makeapbi/${PORTNAME}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Graphical PBI module and package creator

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${LOCALBASE}/bin/gksu:${PORTSDIR}/sysutils/gksu \
		${LOCALBASE}/sbin/pbid:${PORTSDIR}/ports-mgmt/pbi-manager

USE_QT4=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/EasyPBI

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -recursive PREFIX=${PREFIX} EasyPBI.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/EasyPBI ${PREFIX}/bin/EasyPBI
	@${MKDIR} ${DATADIR}/../pbimaker
	@${INSTALL_DATA} ${WRKSRC}/defaulticon.png ${DATADIR}/../pbimaker/

.include <bsd.port.mk>
