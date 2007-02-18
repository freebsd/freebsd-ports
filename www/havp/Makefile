# New ports collection makefile for:	havp
# Date created:				17 June 2006
# Whom:					Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	havp
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.server-side.de/download/ \
				http://bio3k.softboard.ru/uploads/arch/

MAINTAINER=	b3k@mail.ru
COMMENT=	HTTP Antivirus Proxy

LIB_DEPENDS=	clamav.1:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	havp
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

LOG_DIR=	/var/log/havp
TMP_DIR=	/var/tmp/havp
RUN_DIR=	/var/run/havp
PLIST_SUB+=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		this port does not compile on FreeBSD 4.x.
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@[ -f ${PREFIX}/etc/havp/havp.config ] || \
		${CP} -p ${PREFIX}/etc/havp/havp.config.default ${PREFIX}/etc/havp/havp.config
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/havp/blacklist ${EXAMPLESDIR}/blacklist.sample
	@${CP} -R ${WRKSRC}/etc/havp/templates ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/havp/whitelist ${EXAMPLESDIR}/whitelist.sample
	@${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
