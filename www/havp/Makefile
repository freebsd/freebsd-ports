# New ports collection makefile for:	havp
# Date created:				17 June 2006
# Whom:					Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	havp
PORTVERSION=	0.91
CATEGORIES=	www
MASTER_SITES=	http://www.server-side.de/download/ \
		http://bio3k.softboard.ru/uploads/arch/ \
		http://havp.hege.li/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Antivirus Proxy

LIB_DEPENDS=	clamav.6:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_RC_SUBR=	havp
CONFIGURE_ARGS=	--disable-locking

LOG_DIR=	/var/log/havp
TMP_DIR=	/var/tmp/havp
RUN_DIR=	/var/run/havp
PLIST_SUB+=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

OPTIONS=	SSL "Enable SSL proxying (not scanned, only forwarded!)" on \
		CLAMAV "Enable libclamav support" on \
		TROPHIE "Enable Trend Micro (Trophie) support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl-tunnel
.else
CONFIGURE_ARGS+=	--disable-ssl-tunnel
.endif

.if defined(WITH_CLAMAV)
CONFIGURE_ARGS+=	--enable-clamav
.else
CONFIGURE_ARGS+=	--disable-clamav
.endif

.if defined(WITH_TROPHIE)
CONFIGURE_ARGS+=	--enable-trophie
.else
CONFIGURE_ARGS+=	--disable-trophie
.endif

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@[ -f ${PREFIX}/etc/havp/havp.config ] || \
		${CP} ${PREFIX}/etc/havp/havp.config.default ${PREFIX}/etc/havp/havp.config
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/havp/blacklist ${EXAMPLESDIR}/blacklist.sample
	@${CP} -R ${WRKSRC}/etc/havp/templates ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/havp/whitelist ${EXAMPLESDIR}/whitelist.sample
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
