# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oath-toolkit
PORTVERSION=	2.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library, tools, and PAM module for OATH authentication

USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PSKC
OPTIONS_DEFAULT=PSKC

PSKC_DESC=	Portable Symmetric Key Container (RFC 6030) support

MAN1=		oathtool.1
MAN3=		oath_authenticate_usersfile.3 oath_base32_decode.3 \
		oath_base32_encode.3 oath_bin2hex.3 oath_check_version.3 \
		oath_done.3 oath_hex2bin.3 oath_hotp_generate.3 \
		oath_hotp_validate.3 oath_hotp_validate_callback.3 \
		oath_init.3 oath_strerror.3 oath_strerror_name.3 \
		oath_totp_generate.3 oath_totp_validate.3 \
		oath_totp_validate2.3 oath_totp_validate2_callback.3 \
		oath_totp_validate_callback.3

DOCS=		AUTHORS ChangeLog NEWS README

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPSKC}
LIB_DEPENDS+=	xml2:${PORTSDIR}/textproc/libxml2 \
		xmlsec1:${PORTSDIR}/security/xmlsec1

CONFIGURE_ARG+=--with-xml-prefix=${LOCALBASE}

MAN1+=		pskctool.1
MAN3+=		pskc_build_xml.3 pskc_check_version.3 pskc_done.3 \
		pskc_free.3 pskc_get_cryptomodule_id.3 \
		pskc_get_device_devicebinding.3 \
		pskc_get_device_expirydate.3 pskc_get_device_issueno.3 \
		pskc_get_device_manufacturer.3 pskc_get_device_model.3 \
		pskc_get_device_serialno.3 pskc_get_device_startdate.3 \
		pskc_get_device_userid.3 pskc_get_id.3 \
		pskc_get_key_algorithm.3 \
		pskc_get_key_algparm_chall_checkdigits.3 \
		pskc_get_key_algparm_chall_encoding.3 \
		pskc_get_key_algparm_chall_max.3 \
		pskc_get_key_algparm_chall_min.3 \
		pskc_get_key_algparm_resp_checkdigits.3 \
		pskc_get_key_algparm_resp_encoding.3 \
		pskc_get_key_algparm_resp_length.3 \
		pskc_get_key_algparm_suite.3 \
		pskc_get_key_data_b64secret.3 \
		pskc_get_key_data_counter.3 \
		pskc_get_key_data_secret.3 pskc_get_key_data_time.3 \
		pskc_get_key_data_timedrift.3 \
		pskc_get_key_data_timeinterval.3 \
		pskc_get_key_friendlyname.3 pskc_get_key_id.3 \
		pskc_get_key_issuer.3 \
		pskc_get_key_policy_expirydate.3 \
		pskc_get_key_policy_keyusages.3 \
		pskc_get_key_policy_numberoftransactions.3 \
		pskc_get_key_policy_pinencoding.3 \
		pskc_get_key_policy_pinkeyid.3 \
		pskc_get_key_policy_pinmaxfailedattempts.3 \
		pskc_get_key_policy_pinmaxlength.3 \
		pskc_get_key_policy_pinminlength.3 \
		pskc_get_key_policy_pinusagemode.3 \
		pskc_get_key_policy_startdate.3 \
		pskc_get_key_profileid.3 pskc_get_key_reference.3 \
		pskc_get_key_userid.3 pskc_get_keypackage.3 \
		pskc_get_signed_p.3 \
		pskc_get_version.3 pskc_global_done.3 \
		pskc_global_init.3 pskc_global_log.3 \
		pskc_init.3 pskc_keyusage2str.3 pskc_output.3 \
		pskc_parse_from_memory.3 pskc_pinusagemode2str.3 \
		pskc_sign_x509.3 \
		pskc_str2keyusage.3 pskc_str2pinusagemode.3 \
		pskc_str2valueformat.3 pskc_strerror.3 \
		pskc_strerror_name.3 pskc_validate.3 \
		pskc_valueformat2str.3 pskc_verify_x509crt.3

PLIST_SUB+=	PSKC=""
.else
CONFIGURE_ARGS+=--disable-pskc
PLIST_SUB+=	PSKC="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} 's|install-data-am: install-data-local|install-data-am:|' \
		${WRKSRC}/liboath/gtk-doc/Makefile.in \
		${WRKSRC}/libpskc/gtk-doc/Makefile.in
.else
	@${REINPLACE_CMD} 's|@HTML_DIR@|${DOCSDIR}|' \
		${WRKSRC}/liboath/gtk-doc/Makefile.in \
		${WRKSRC}/libpskc/gtk-doc/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/pam_oath
	${INSTALL_DATA} ${WRKSRC}/pam_oath/README ${DOCSDIR}/pam_oath/
.endif

.include <bsd.port.mk>
