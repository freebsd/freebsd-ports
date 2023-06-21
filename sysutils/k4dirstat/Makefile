PORTNAME=	k4dirstat
DISTVERSION=	3.4.3
CATEGORIES=	sysutils kde

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	KDE utility that sums up disk usage for directory trees
WWW=		https://github.com/jeromerobert/k4dirstat

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang cpe kde:5 qt:5
CPE_VENDOR=	kdirstat_project
CPE_PRODUCT=	kdirstat
USE_GITHUB=	yes
GH_ACCOUNT=	jeromerobert
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		i18n iconthemes jobwidgets kio service widgetsaddons xmlgui
USE_QT=		core dbus gui network widgets xml buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Categories/s|=.*|=Qt;KDE;Utility;|' \
		${WRKSRC}/src/k4dirstat.desktop
	@${REINPLACE_CMD} -e \
		's|<sys/errno.h>|<errno.h>|' \
		${WRKSRC}/src/kdirreadjob.cpp
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/doc/en/CMakeLists.txt

.include <bsd.port.mk>
