# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qkismet
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/qKismet/${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Qt 4 GUI client for Kismet

RUN_DEPENDS=	kismet:net-mgmt/kismet

USES=		qmake tar:bzip2
USE_QT4=	gui xml uic_build moc_build rcc_build network

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

do-patch:
	${REINPLACE_CMD} -e 's,:/img/,${DATADIR}/img/,g' \
	${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../build/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} img ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
