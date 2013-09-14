# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	havp
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.server-side.de/download/ \
		http://bio3k.softboard.ru/uploads/arch/ \
		http://havp.hege.li/download/

MAINTAINER=	ayu@commun.jp
COMMENT=	HTTP Antivirus Proxy

LIB_DEPENDS=	clamav.7:${PORTSDIR}/security/clamav

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_RC_SUBR=	havp
CONFIGURE_ARGS=	--disable-locking

LOG_DIR=	/var/log/havp
TMP_DIR=	/var/tmp/havp
RUN_DIR=	/var/run/havp
PLIST_SUB+=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

OPTIONS_DEFINE=	SSL CLAMAV TROPHIE
OPTIONS_DEFAULT=	SSL CLAMAV
SSL_DESC=	SSL proxying (not scanned, only forwarded!)
CLAMAV_DESC=	libclamav support
TROPHIE_DESC=	Trend Micro (Trophie) support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--enable-ssl-tunnel
.else
CONFIGURE_ARGS+=	--disable-ssl-tunnel
.endif

.if ${PORT_OPTIONS:MCLAMAV}
CONFIGURE_ARGS+=	--enable-clamav
.else
CONFIGURE_ARGS+=	--disable-clamav
.endif

.if ${PORT_OPTIONS:MTROPHIE}
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

.include <bsd.port.mk>
