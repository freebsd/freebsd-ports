# New ports collection makefile for:	c-icap
# Date created:				30 January 2006
# Whom:					Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	c-icap
PORTVERSION=	030606
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
				http://bio3k.softboard.ru/uploads/arch/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	c_icap-${PORTVERSION}rc1

MAINTAINER=	b3k@mail.ru
COMMENT=	An implementation of an ICAP server

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	c_icap
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/c_icap

SUB_FILES=	pkg-install pkg-deinstall

OPTIONS=	CLAMAV "Build with srv_clamav service" on \
			LARGE_FILES "Enable large files support" off \
			IPV6 "Enable IPv6 support" off
#		PERL "With Perl support" off

.include <bsd.port.pre.mk>

# Perl support not ready yet. Try to contact author or hack it by yourself.
WITHOUT_PERL=	yes

LOG_DIR=	/var/log/c_icap
TMP_DIR=	/var/tmp
RUN_DIR=	/var/run
PLIST_SUB+=	LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	LOG_DIR=${LOG_DIR} TMP_DIR=${TMP_DIR} RUN_DIR=${RUN_DIR}

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
CONFIGURE_ARGS+=	--with-perl=${PERL}
.else
PLIST_SUB+=	PERL="@comment "
CONFIGURE_ARGS+=	--without-perl
.endif

.if !defined(WITHOUT_CLAMAV)
LIB_DEPENDS+=	clamav.2:${PORTSDIR}/security/clamav
PLIST_SUB+=	CLAMAV=""
CONFIGURE_ARGS+=	--with-clamav
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
PLIST_SUB+=	CLAMAV="@comment "
CONFIGURE_ARGS+=	--without-clamav
.endif

.if defined(WITH_LARGE_FILES)
CONFIGURE_ARGS+=	--enable-large-files
.else
CONFIGURE_ARGS+=	--disable-large-files
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-extract:
	@${MV} ${WRKSRC}/c-icap.conf ${WRKSRC}/c-icap.conf.default
	@${MV} ${WRKSRC}/c-icap.conf.in ${WRKSRC}/c-icap.conf.default.in
	@${MV} ${WRKSRC}/c-icap.magic ${WRKSRC}/c-icap.magic.default

post-patch:
	@${REINPLACE_CMD} -e 's|User wwwrun|User cicap|g' \
		-e 's|Group nobody|Group cicap|g' \
		-e 's|/var/run|${RUN_DIR}|g' \
		-e 's|/var/tmp|${TMP_DIR}|g' \
		-e 's|/var/log/c_icap|${LOG_DIR}|g' \
		${WRKSRC}/c-icap.conf.default ${WRKSRC}/c-icap.conf.default.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|icap_stretch_CFLAGS = -Iinclude/|icap_stretch_CFLAGS = -Iinclude/ ${PTHREAD_CFLAGS}|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am
.if !defined(WITH_PERL)
	@${REINPLACE_CMD} -e 's|\(^Module perl\)|\#\1|g' \
	${WRKSRC}/c-icap.conf.default.in
.endif
.if !defined(WITH_CLAMAV)
	@${REINPLACE_CMD} -e 's|\(^Service antivirus\)|\#\1|g' \
		-e 's|\(^srv_clamav\)|\#\1|g' \
		${WRKSRC}/c-icap.conf.default.in
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@[ -f ${PREFIX}/etc/c-icap.conf ] || \
		${CP} -p ${PREFIX}/etc/c-icap.conf.default ${PREFIX}/etc/c-icap.conf
	@[ -f ${PREFIX}/etc/c-icap.magic ] || \
		${CP} -p ${PREFIX}/etc/c-icap.magic.default ${PREFIX}/etc/c-icap.magic
	@${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
