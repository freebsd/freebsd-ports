# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	kdirstat
PORTVERSION=	2.7.8
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	https://bitbucket.org/jeromerobert/k4dirstat/get/
DISTNAME=	k4dirstat-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	KDE utility that sums up disk usage for directory trees

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/jeromerobert-k4dirstat-3a4663ee20e7

USES=		cmake cpe gettext-tools kde:4 tar:bzip2
CPE_VENDOR=	kdirstat_project
USE_KDE=	automoc4 kdelibs libkonq
USE_QT4=	corelib dbus gui network qt3support svg xml \
		moc_build qmake_build rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Categories/s|=.*|=Qt;KDE;Utility;|' \
		${WRKSRC}/src/k4dirstat.desktop
	@${REINPLACE_CMD} -e \
		's|<sys/errno.h>|<errno.h>|' \
		${WRKSRC}/src/kdirreadjob.cpp

post-install:
	@${LN} -sf k4dirstat ${STAGEDIR}${PREFIX}/bin/kdirstat

.include <bsd.port.mk>
