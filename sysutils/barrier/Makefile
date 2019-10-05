# $FreeBSD$

PORTNAME=	barrier
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.2
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang localbase:ldflags pkgconfig ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	debauchee
USE_XORG=	ice sm x11 xext xi xinerama xrandr xtst

CMAKE_ARGS=	-DBARRIER_BUILD_DATE=00000000

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		EXAMPLES GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_DESC=	Build configuration utility (requires Qt 5)

GUI_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libdns_sd.so:net/avahi-libdns
GUI_USES=		qt:5
GUI_USE=		QT=core,gui,network,widgets,buildtools_build,qmake_build
GUI_CMAKE_BOOL=		BARRIER_BUILD_GUI

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc/barrier/|"${ETCDIR}/|' \
		${WRKSRC}/src/lib/arch/unix/ArchDaemonUnix.h
	@${REINPLACE_CMD} -e 's|/etc/barrier.conf|${ETCDIR}/barrier.conf|' \
		${WRKSRC}/doc/barriers.1

post-install:
	cd ${INSTALL_WRKSRC}/bin && \
		${INSTALL_PROGRAM} barrierc barriers ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} barrierc.1 barriers.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/barrier.conf.example-basic \
		${STAGEDIR}${ETCDIR}/barrier.conf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} barrier.conf.example barrier.conf.example-advanced \
		barrier.conf.example-basic ${STAGEDIR}${EXAMPLESDIR}

post-install-GUI-on:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/barrier ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
