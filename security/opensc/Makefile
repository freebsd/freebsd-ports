# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	opensc
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc.org/files/

MAINTAINER=	bms@FreeBSD.org
COMMENT=	ISO 7816 Smartcard API

RUN_DEPENDS=	${LOCALBASE}/bin/pkg-config:${PORTSDIR}/devel/pkgconfig

INSTALLS_SHLIB= yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MANCOMPRESSED=	no
MAN1=	pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1 opensc-tool.1 \
	opensc-explorer.1 opensc-config.1 cryptoflex-tool.1
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
# WITH_USBTOKEN WITH_DOCBOOK WITH_MOZILLA
#
# Default: WITH_PAM, WITH_PCSC_LITE, WITH_LDAP.
#
CONFIGURE_ARGS=		--prefix=${PREFIX} --disable-dependency-tracking

.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif
.if !defined(WITHOUT_PCSC_LITE)
LIB_DEPENDS+=		pcsclite.0:${PORTSDIR}/devel/pcsc-lite
CONFIGURE_ARGS+=	--with-pcsclite=${LOCALBASE}
.endif

.if !defined(WITHOUT_LDAP)
WITH_OPENLDAP_VER?=	21
.if ${WITH_OPENLDAP_VER} == "21"
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap21-client
.elif ${WITH_OPENLDAP_VER} == "20"
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap20-client
.endif

CONFIGURE_ARGS+=	--enable-ldap			\
			--with-ldap-lib=openldap	\
			--with-ldap-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !defined(WITH_DOCBOOK)
CONFIGURE_ARGS+=	--without-docbook
.endif

# XXX USB token support doesn't work yet on FreeBSD. Accepting patches.
.if defined(WITH_USBTOKEN)
CONFIGURE_ARGS+=	--enable-usbtoken
.endif
.if defined(WITH_MOZILLA)
CONFIGURE_ARGS+=	--with-plugin-dir=${X11BASE}/lib/mozilla/plugins
.endif

.include <bsd.port.mk>
