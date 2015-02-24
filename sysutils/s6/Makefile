# Created by: Colin Booth <colin@heliocat.net>
# $FreeBSD$

PORTNAME=	s6
PORTVERSION=	2.1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	colin@heliocat.net
COMMENT=	skarnet.org supervision suite

LICENSE=	ISCL

BUILD_DEPENDS=	skalibs>=2.3.0.0:${PORTSDIR}/devel/skalibs \
		execline>=2.0.2.1:${PORTSDIR}/lang/execline
RUN_DEPENDS=	execlineb:${PORTSDIR}/lang/execline

USES=		gmake
USE_RC_SUBR=	s6
SERVICE_DIR?=	/var/service
SUB_FILES=	s6-svscan_finish s6-svscan-log_run s6-svscanboot s6-svscan_env_PATH
SUB_LIST=	SERVICE_DIR="${SERVICE_DIR}"

DOCS=		AUTHORS COPYING INSTALL README doc/*.html

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-default-path=${LOCALBASE}/bin:/usr/bin:/bin \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib/skalibs \
	--with-lib=${LOCALBASE}/lib/execline \
	--enable-shared

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs6.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/s6lockd-helper
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}
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

.include <bsd.port.mk>
