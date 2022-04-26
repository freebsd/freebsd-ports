PORTNAME=	barrier
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	sysutils

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang cpe localbase:ldflags pkgconfig ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	debauchee gulrak:gulrak
GH_PROJECT=	filesystem:gulrak
GH_TAGNAME= v1.5.12:gulrak
USE_XORG=	ice sm x11 xext xi xinerama xrandr xtst
CPE_VENDOR=	barrier_project

CMAKE_ARGS=	-DBARRIER_BUILD_DATE=00000000 \
						-DBARRIER_BUILD_TESTS=OFF

CONFLICTS_INSTALL=	clusterit # bin/barrier

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

post-extract:
	@${CP} -a ${WRKSRC_gulrak}/include ${WRKSRC}/ext/gulrak-filesystem/

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc/barrier/|"${ETCDIR}/|' \
		${WRKSRC}/src/lib/arch/unix/ArchDaemonUnix.h
	@${REINPLACE_CMD} -e 's|/etc/barrier.conf|${ETCDIR}/barrier.conf|' \
		${WRKSRC}/doc/barriers.1

post-install:
	cd ${INSTALL_WRKSRC}/bin && \
		${INSTALL_PROGRAM} barrierc barriers ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} barrierc.1 barriers.1 ${STAGEDIR}${PREFIX}/share/man/man1
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
