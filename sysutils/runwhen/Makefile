PORTNAME=	runwhen
DISTVERSION=	2021.04.30
PORTREVISION=   3
CATEGORIES=	sysutils
MASTER_SITES=	http://code.dogmap.org/runwhen/releases/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Tools for running commands at particular times
WWW=		http://code.dogmap.org/runwhen/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/package/LICENSE

BUILD_DEPENDS=  skalibs>=2.14.1.1:devel/skalibs
LIB_DEPENDS=	libskarnet.so:devel/skalibs

USES=		localbase tar:bzip2

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

PLIST_FILES=	bin/rw-add bin/rw-match bin/rw-max bin/rw-min	\
		bin/rw-sleep bin/rw-sub bin/rw-touch

post-patch:
	@${REINPLACE_CMD} -e 's!gcc -O2!${CC} ${CFLAGS}!' \
		${WRKSRC}/conf-compile/defaults/host_compile.sh
	@${REINPLACE_CMD} 's!gcc!${CC} ${LDFLAGS} ${LIBS}!' \
		${WRKSRC}/conf-compile/defaults/host_link.sh

do-configure:
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-compile/defaults/package_home
	${ECHO_CMD} ${LOCALBASE} > ${WRKSRC}/conf-compile/defaults/depend_skalibs
	${ECHO_CMD} ${LOCALBASE}/lib/skalibs/sysdeps > ${WRKSRC}/conf-compile/defaults/depend_skalibs_sysdeps

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
