PORTNAME=	s6
PORTVERSION=	2.11.1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Skarnet.org supervision suite

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	execline>=2.9.0.0:lang/execline
LIB_DEPENDS=	libskarnet.so:devel/skalibs
RUN_DEPENDS=	execlineb:lang/execline

USES=		gmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	s6

SERVICE_DIR?=	/var/service
SUB_FILES=	s6-svscan_finish s6-svscan-log_run s6-svscanboot s6-svscan_env_PATH
SUB_LIST=	SERVICE_DIR="${SERVICE_DIR}"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-default-path=${LOCALBASE}/bin:/usr/bin:/bin \
		--with-include=${LOCALBASE}/include \
		--with-dynlib=${LOCALBASE}/lib \
		--with-lib=${LOCALBASE}/lib/skalibs \
		--with-lib=${LOCALBASE}/lib/execline \
		--enable-shared

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS README doc/*.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs6.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/s6lockd-helper
	cd ${WRKDIR} && ${INSTALL_SCRIPT} s6-svscanboot \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}/s6-svscan/env
	cd ${WRKDIR} && ${INSTALL_SCRIPT} s6-svscan_finish \
		${STAGEDIR}${ETCDIR}/s6-svscan/finish.sample
	cd ${WRKDIR} && ${INSTALL_DATA} s6-svscan_env_PATH \
		${STAGEDIR}${ETCDIR}/s6-svscan/env/PATH.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}/s6-svscan-log
	cd ${WRKDIR} && ${INSTALL_SCRIPT} s6-svscan-log_run \
		${STAGEDIR}${ETCDIR}/s6-svscan-log/run.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
