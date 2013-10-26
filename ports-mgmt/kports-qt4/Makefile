# Created by: Hannes Hauswedell <hannes.hauswedell@gmail.com>
# $FreeBSD$

PORTNAME=	kports
PORTVERSION=	0.8.2
PORTREVISION=	6
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	SF

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Qt4-Version of your favorite frontend to the Ports

RUN_DEPENDS=	portaudit:${PORTSDIR}/ports-mgmt/portaudit \
		uma:${PORTSDIR}/sysutils/bsdadminscripts

CONFLICTS=	kports-0.[0-7]*

USE_BZIP2=	yes

USE_QT4=	corelib gui network qmake_build moc_build uic_build rcc_build
QMAKE_ARGS+=	PREFIX=${PREFIX}

HAS_CONFIGURE=	yes

LATEST_LINK=	kports-qt4

OPTIONS_DEFINE=	DEBUG OXYGEN KDEBASE
OPTIONS_DEFAULT=	OXYGEN KDEBASE
OXYGEN_DESC=	Pull in Oxygen icons (recommended)
KDEBASE_DESC=	Pull in kdebase-runtime for kdesu

.if defined(WITH_PKGNG)
IGNORE=		only works with traditional pkg-tools
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOXYGEN}
USE_KDE4=	oxygen
.endif

.if ${PORT_OPTIONS:MKDEBASE}
USE_KDE4=	runtime
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/data/kports.desktop

.if ${PORT_OPTIONS:MDEBUG}
pre-configure:
	@(${ECHO_CMD} "CONFIG += debug" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "CONFIG -= release warn_off" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "CONFIG += debug warn_on" >> ${WRKSRC}/src/src.pro)
	@(${ECHO_CMD} "DEFINES -= QT_NO_DEBUG_OUTPUT" >> ${WRKSRC}/src/src.pro)
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix ${QMAKE_ARGS} kports.pro

post-install:
.if ! ${PORT_OPTIONS:MOXYGEN}
	@${CAT} pkg-message.nooxygen
.endif

.if ! ${PORT_OPTIONS:MKDEBASE}
	@${CAT} pkg-message.nokdebase
.endif

.include <bsd.port.mk>
