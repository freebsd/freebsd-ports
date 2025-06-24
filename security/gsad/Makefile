PORTNAME=	gsad
DISTVERSIONPREFIX=	v
DISTVERSION=	24.3.0
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Security Assistant HTTP server
WWW=		https://github.com/greenbone/gsad

LICENSE=	AGPLv3+

LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libmicrohttpd.so:www/libmicrohttpd
RUN_DEPENDS=	doxygen>0:devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}polib>=0:devel/py-polib@${PY_FLAVOR}

USES=		cmake gettext-runtime gnome pkgconfig python
USE_GNOME=	glib20 libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	gsad

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	gsad

LDFLAGS+=	-lm

ETCDIR=		${PREFIX}/etc/gvm

post-extract:
	@${MV} ${WRKSRC}/src/gsad_log_conf.cmake_in ${WRKSRC}/src/gsad_log.conf.sample

post-patch:
	${REINPLACE_CMD} -e 's|$${GVM_LOG_DIR}|/var/log/gvm|g' ${WRKSRC}/src/gsad_log.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/gsad
	@${MKDIR} ${STAGEDIR}/var/run/gvm
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/src/gsad_log.conf.sample ${STAGEDIR}${ETCDIR}

	@${ECHO_CMD} "@sample etc/gvm/gsad_log.conf.sample" >> ${TMPPLIST}
	@${ECHO_CMD} "sbin/gsad" >> ${TMPPLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "share/man/man8/gsad.8.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(gvm,gvm,750) /var/run/gsad" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir(gvm,gvm,750) /var/run/gvm" >> ${TMPPLIST}

.include <bsd.port.mk>
