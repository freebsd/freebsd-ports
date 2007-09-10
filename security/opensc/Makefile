# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	opensc
DISTVERSION=	0.11.4
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/ \
		http://www.opensc-project.org/files/${PORTNAME}/testing/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

OPTIONS=	OPENCT "Enable direct OpenCT backend support" on \
		PCSC "Enable PC/SC backend support" off \
		SIGNER "Enable signer browser plugin" off

USE_AUTOTOOLS=	libltdl:15
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -I${X11BASE}/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

DOC_FILES=	README *.sh *.xsl *.css *.html api html tools

PORTDOCS=	*

MANCOMPRESSED=	no
MAN1=		cardos-info.1 cryptoflex-tool.1 netkey-tool.1 \
		opensc-config.1 opensc-explorer.1 opensc-tool.1 \
		pkcs11-tool.1 pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1
MAN3=		sc_app_info_t.3 sc_append_record.3 sc_asn1_decode.3 \
		sc_asn1_encode.3 sc_asn1_entry.3 sc_asn1_find_tag.3 \
		sc_asn1_print_tags.3 sc_asn1_put_tag.3 sc_asn1_read_tag.3 \
		sc_asn1_skip_tag.3 sc_asn1_verify_tag.3 sc_base64_decode.3 \
		sc_base64_encode.3 sc_card_ctl.3 sc_card_t.3 \
		sc_card_valid.3 sc_check_sw.3 sc_connect_card.3 \
		sc_copy_asn1_entry.3 sc_create_file.3 sc_delete_file.3 \
		sc_delete_record.3 sc_der_clear.3 sc_der_copy.3 \
		sc_detect_card_presence.3 sc_disconnect_card.3 \
		sc_enum_apps.3 sc_establish_context.3 sc_file_dup.3 \
		sc_file_free.3 sc_file_new.3 sc_file_t.3 \
		sc_find_app_by_aid.3 sc_find_pkcs15_app.3 sc_format_apdu.3 \
		sc_format_asn1_entry.3 sc_free_apps.3 sc_get_cache_dir.3 \
		sc_get_challenge.3 sc_get_data.3 sc_list_files.3 \
		sc_lock.3 sc_make_cache_dir.3 sc_put_data.3 \
		sc_read_binary.3 sc_read_record.3 sc_release_context.3 \
		sc_select_file.3 sc_set_card_driver.3 sc_strerror.3 \
		sc_transmit_apdu.3 sc_unlock.3 sc_update_binary.3 \
		sc_update_dir.3 sc_update_record.3 sc_wait_for_event.3 \
		sc_write_binary.3 sc_write_record.3
MAN5=		pkcs15-profile.5

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENCT)
LIB_DEPENDS+=	openct.1:${PORTSDIR}/security/openct
.else
CONFIGURE_ARGS+=--disable-openct
.endif

.if defined(WITH_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
.else
CONFIGURE_ARGS+=--disable-pcsc-lite
.endif

.if defined(WITH_SIGNER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libassuan.a:${PORTSDIR}/security/libassuan
PINENTRY?=	${LOCALBASE}/bin/pinentry
PINENTRY_PORT?=	security/pinentry
RUN_DEPENDS+=	pinentry:${PORTSDIR}/${PINENTRY_PORT}
USE_XLIB=	yes
CONFIGURE_ARGS+=--with-libassuan-prefix=${LOCALBASE} \
		--with-plugin-dir=${LOCALBASE}/lib/browser_plugins \
		--with-pin-entry=${PINENTRY}
PLIST_SUB+=	SIGNER=""
.else
CONFIGURE_ARGS+=--disable-nsplugin
PLIST_SUB+=	SIGNER="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${PREFIX}/etc/opensc.conf-sample
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${CP} -R ${DOC_FILES} ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
