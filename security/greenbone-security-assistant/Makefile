# $FreeBSD$

PORTNAME=	greenbone-security-assistant
DISTVERSION=	20.8.0
DISTVERSIONPREFIX=	v
MASTER_SITES=   LOCAL/acm/gsa/:yarn_cache
CATEGORIES=	security
DISTFILES=	${PORTNAME}-cache${EXTRACT_SUFX}:yarn_cache

MAINTAINER=	acm@FreeBSD.org
COMMENT=	libraries module for the GVM solution

LICENSE=	AGPLv3+

BUILD_DEPENDS=	node:www/node \
		yarn:www/yarn
LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libmicrohttpd.so:www/libmicrohttpd
RUN_DEPENDS=	doxygen>0:devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}polib>=0:devel/py-polib@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	gsa

CMAKE_ARGS+=	-DINSTALLER_ARGS="--offline"

USES=		cmake gettext-runtime gnome pkgconfig python
USE_GNOME=	glib20 libxml2

USE_RC_SUBR=	gsad

ETCDIR=		${PREFIX}/etc/gvm
PLIST_FILES=	"@sample %%ETCDIR%%/gsad_log.conf.sample"

post-extract:
	@${MV} ${WRKSRC}/gsad/src/gsad_log_conf.cmake_in ${WRKSRC}/gsad/src/gsad_log.conf.sample

post-patch:
	${ECHO_CMD} 'yarn-offline-mirror "${WRKDIR}/yarn-offline-cache"' >> \
		${WRKSRC}/.yarnrc
	${REINPLACE_CMD} -e 's|$${GVM_LOG_DIR}|/var/log/gvm|g' ${WRKSRC}/gsad/src/gsad_log.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/gvm
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/gsad/src/gsad_log.conf.sample ${STAGEDIR}${ETCDIR}
	
	@${ECHO_CMD} "@sample %%ETCDIR%%/gsad_log.conf.sample"
	@${ECHO_CMD} "etc/rc.d/gsad" >> ${TMPPLIST}
	@${ECHO_CMD} "sbin/gsad" >> ${TMPPLIST}

	@cd ${WRKSRC}/gsa/build && \
		${FIND} -s img locales static -not -type d \
			-exec ${ECHO_CMD} "share/gvm/gsad/web/{}" \; >> ${TMPPLIST}

	@${ECHO_CMD} "share/man/man8/gsad.8.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir /var/run/gvm" >> ${TMPPLIST}

.include <bsd.port.mk>
