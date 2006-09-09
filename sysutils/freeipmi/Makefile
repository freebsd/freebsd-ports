# New ports collection makefile for:	freeipmi
# Date created:				20/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	freeipmi
PORTVERSION=	0.2.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.zresearch.com/pub/freeipmi/${PORTVERSION}/

PATCH_SITES=	ftp://ftp.riss-telecom.ru/pub/patches/
PATCHFILES=	${DISTNAME}-fbsd1.diff

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	Library and tools to support IPMI-capable hardware

BUILD_DEPENDS+=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

OPTIONS+=	FISH "Build fish (FreeIPMI shell) and scripts" on

USE_AUTOTOOLS=	autoconf:259 libtool:15 aclocal:19 automake:19
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
NOT_FOR_ARCHS=	ia64 sparc64 alpha
PLIST_SUB+=	SHLIBVER=${SHLIBVER}
MAN5+=	ipmipower.conf.5
MAN8+=	bmc-info.8 bmc-watchdog.8 ipmi-locate.8 ipmi-raw.8 \
	ipmiping.8 ipmipower.8 rmcpping.8
INFO+=		freeipmi freeipmi-faq
PORTDOCS=	*
PKGDEINSTALL=	${PKGINSTALL}

SHLIBVER=	2

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.if defined(WITH_IOPERM)
CPPFLAGS+=	-DUSE_IOPERM
.endif
.if defined(WITH_FISH)
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--enable-fish
PLIST_SUB+=	FISH=""
MAN5+=	bmc-config.conf.5
MAN8+=	bmc-config.8 fish.8 ipmi-sel.8 ipmi-sensors.8
.else
CONFIGURE_ARGS+=	--disable-fish
PLIST_SUB+=	FISH="@comment "
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/fish
	${INSTALL_DATA} ${WRKSRC}/fish/fish.scm \
		${PREFIX}/etc/fish/fish.scm-dist
	${INSTALL_DATA} ${WRKSRC}/fish/extensions/ipmi-sensors-conf.scm \
		${PREFIX}/etc/fish/ipmi-sensors-conf.scm-dist
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
