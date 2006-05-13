# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	opensc
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/opensc/

MAINTAINER=	simon@FreeBSD.org
COMMENT=	ISO 7816 Smartcard API

USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MANCOMPRESSED=	no
MAN1=	pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1 opensc-tool.1 \
	opensc-explorer.1 opensc-config.1 cryptoflex-tool.1 \
	pkcs11-tool.1 cardos-info.1
MAN3=	sc_select_file.3 sc_release_context.3 sc_read_record.3 \
	sc_read_binary.3 sc_pkcs15_compute_signature.3 sc_lock.3 \
	sc_list_files.3 sc_file_new.3 sc_file_free.3 sc_file.3 \
	sc_establish_context.3 sc_disconnect_card.3 \
	sc_detect_card_presence.3 sc_connect_card.3
MAN5=	pkcs15-profile.5
MAN7=	pkcs15.7 opensc.7

# Compilation Options
#
# Define boolean switches:
# WITHOUT_PAM WITHOUT_PCSC_LITE WITHOUT_LDAP
# WITH_DEBUG WITH_DOCBOOK WITH_FIREFOX_PLUGIN WITH_MOZILLA_PLUGIN
#
# Default: WITH_PAM, WITH_PCSC_LITE, WITH_LDAP.
#
CONFIGURE_ARGS=		--prefix=${PREFIX} --disable-dependency-tracking

.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif

.if !defined(WITHOUT_PCSC_LITE)
LIB_DEPENDS+=		pcsclite.1:${PORTSDIR}/devel/pcsc-lite
CONFIGURE_ARGS+=	--with-pcsclite=${LOCALBASE}
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap			\
			--with-ldap-lib=openldap	\
			--with-ldap-dir=${LOCALBASE}
PLIST_SUB+=		LDAP=""
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

.if defined(WITH_FIREFOX_PLUGIN)
RUN_DEPENDS?=		firefox:${PORTSDIR}/www/firefox
PLUGIN_DIR?=		lib/firefox/plugins
CONFIGURE_ARGS+=	--with-plugin-dir="${PREFIX}/${PLUGIN_DIR}"
.elif defined(WITH_MOZILLA_PLUGIN)
RUN_DEPENDS?=		mozilla:${PORTSDIR}/www/mozilla
PLUGIN_DIR?=		lib/browser_plugins
CONFIGURE_ARGS+=	--with-plugin-dir="${PREFIX}/${PLUGIN_DIR}"
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined(WITH_DOCBOOK)
CONFIGURE_ARGS+=	--without-docbook
.endif

.if defined(WITH_OPENCT)
CONFIGURE_ARGS+=	--with-openct=${LOCALBASE}
RUN_DEPENDS+=		openct-tool:${PORTSDIR}/security/openct
BUILD_DEPENDS+=		${RUN_DEPENDS}
.endif

.include <bsd.port.pre.mk>
#
#
#post-patch:
#	${REINPLACE_CMD} -e "s,ulong,u_long," ${WRKSRC}/src/openscd/openscd.c

.include <bsd.port.post.mk>
