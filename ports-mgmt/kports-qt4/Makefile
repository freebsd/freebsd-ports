# Created by: Hannes Hauswedell <hannes.hauswedell@gmail.com>
# $FreeBSD$

PORTNAME=	kports
PORTVERSION=	0.8.2
PORTREVISION=	9
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	SF

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Qt4-Version of your favorite frontend to the Ports

RUN_DEPENDS=	portaudit:${PORTSDIR}/ports-mgmt/portaudit \
		uma:${PORTSDIR}/sysutils/bsdadminscripts

CONFLICTS=	kports-0.[0-7]*

USES=		qmake tar:bzip2
USE_QT4=	corelib gui network moc_build uic_build rcc_build

OPTIONS_DEFINE=	DEBUG OXYGEN KDEBASE
OPTIONS_DEFAULT=	OXYGEN KDEBASE
OXYGEN_DESC=	Pull in Oxygen icons (recommended)
OXYGEN_USE=	KDE4=oxygen
KDEBASE_DESC=	Pull in kdebase-runtime for kdesu
KDEBASE_USE=	KDE4=runtime

.if defined(WITH_PKGNG)
IGNORE=		only works with traditional pkg-tools
.endif

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/data/kports.desktop

.if ${PORT_OPTIONS:MDEBUG}
pre-configure:
	@(${ECHO_CMD} "CONFIG += debug" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "CONFIG -= release warn_off" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "CONFIG += debug warn_on" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "DEFINES -= QT_NO_DEBUG_OUTPUT" >> ${WRKSRC}/src/src.pro)
.endif

.include <bsd.port.mk>
