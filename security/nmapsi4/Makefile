# New ports collection makefile for:	nmapsi4
# Date created:		2009-10-30
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	nmapsi4
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	GUI frontend for the nmap scanning utility

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap

USE_CMAKE=	yes
USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build network \
		linguist webkit

pre-configure:
	${REINPLACE_CMD} -e 's#share/applications/kde4/#share/applications/#g' \
		${WRKSRC}/${PORTNAME}/CMakeLists.txt \
		${WRKSRC}/${PORTNAME}-logr/CMakeLists.txt

post-install:
	${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}-logr

.include <bsd.port.mk>
