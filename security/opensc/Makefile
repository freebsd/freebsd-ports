# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	opensc
PORTVERSION=	0.11.8
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/ \
		http://www.opensc-project.org/files/${PORTNAME}/testing/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

OPTIONS=	OPENCT "Enable direct OpenCT backend support" on \
		PCSC "Enable PC/SC backend support" off \
		SIGNER "Enable signer browser plugin" off

USE_AUTOTOOLS=	libltdl:15
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib -liconv" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

MANCOMPRESSED=	no
MAN1=		cardos-tool.1 cryptoflex-tool.1 netkey-tool.1 \
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
CONFIGURE_ARGS+=--enable-openct
.endif

.if defined(WITH_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
CONFIGURE_ARGS+=--enable-pcsc
.endif

.if defined(WITH_SIGNER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libassuan.a:${PORTSDIR}/security/libassuan
PINENTRY?=	${LOCALBASE}/bin/pinentry
PINENTRY_PORT?=	security/pinentry
RUN_DEPENDS+=	pinentry:${PORTSDIR}/${PINENTRY_PORT}
USE_XORG=	x11
CONFIGURE_ARGS+=--enable-nsplugin \
		--with-libassuan-prefix=${LOCALBASE} \
		--with-plugindir=${WEBPLUGINS_DIR} \
		--with-pinentry=${PINENTRY}
PLIST_SUB+=	SIGNER=""

USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=opensc-signer.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
PLIST_SUB+=	SIGNER="@comment "
.endif

.ifndef(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
.if !defined(WITH_SIGNER)
	@${REINPLACE_CMD} 's|install-data-am: install-pluginDATA|install-data-am:|' \
		${WRKSRC}/src/signer/Makefile.in
.endif
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA install-dist_htmlDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
