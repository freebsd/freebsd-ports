# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	k4dirstat
PORTVERSION=	3.2.1
CATEGORIES=	sysutils kde

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	KDE utility that sums up disk usage for directory trees

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext-tools \
		kde:5 qt:5 tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	jeromerobert

CPE_VENDOR=	kdirstat_project
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		i18n iconthemes jobwidgets kio service widgetsaddons xmlgui
USE_QT=		buildtools_build core gui dbus network qmake_build widgets xml

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Categories/s|=.*|=Qt;KDE;Utility;|' \
		${WRKSRC}/src/k4dirstat.desktop
	@${REINPLACE_CMD} -e \
		's|<sys/errno.h>|<errno.h>|' \
		${WRKSRC}/src/kdirreadjob.cpp

.include <bsd.port.mk>
