# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qkismet
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/qKismet/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 GUI client for Kismet

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	kismet:net-mgmt/kismet

USES=		qmake qt:4 tar:bzip2
USE_QT=		gui xml uic_build moc_build rcc_build network

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

do-patch:
	${REINPLACE_CMD} -e 's,:/img/,${DATADIR}/img/,g' \
	${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../build/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} img ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
