# New ports collection makefile for:    OpenLDAP 2.1
# Date created:		5 Dec 2002
# Whom:			Christian Kratzer <ck@cksoft.de>
#
# This port allows separation of the openldap client and servers
# using following options
#
# default	builds openldap21-PORTVERSION
# CLIENT_ONLY 	builds openldap21-client-PORTVERSION (clients and libs)
# SLAPD_ONLY 	builds openldap21-slapd-PORTVERSION  (slapd and slapd tools)
# SLURPD_ONLY 	builds openldap21-slurpd-PORTVERSION (slurpd only)
# SERVERS_ONLY 	builds openldap21-servers-PORTVERSION (slapd and slurpd)
# WITHOUT_SASL	do not build against sasl2
#
# OPENLDAP_STABLE an attempt to track the openldap stable branch
#		It remains to be seen if this stays practical.
#
# $FreeBSD$
#

PORTNAME=	openldap21
PORTVERSION=	2.1.20
PORTREVISION=	1
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/		\
		http://public.planetmirror.com/pub/openldap/%SUBDIR%/	\
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/\
		ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/		\
		ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/		\
		ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/	\
		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/	\
		ftp://ftp.si.uniovi.es/mirror/OpenLDAP/%SUBDIR%/	\
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/	\
		ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
.if defined(OPENLDAP_STABLE)
MASTER_SITE_SUBDIR=	openldap-stable
DISTNAME=	openldap-stable-20030410
PKGNAMESUFFIX=	-stable
WRKSRC=		${WRKDIR}/openldap-${PORTVERSION}
.else
MASTER_SITE_SUBDIR=	openldap-release
DISTNAME=	openldap-${PORTVERSION}
.endif
EXTRACT_SUFX=	.tgz

MAINTAINER=	ck@cksoft.de
COMMENT=	Open source LDAP client and server software

LIB_DEPENDS+=	db41:${PORTSDIR}/databases/db41

CXXFLAGS+=	-D_REENTRANT ${PTHREAD_CFLAGS}	\
		-I${LOCALBASE}/include		\
		-I${LOCALBASE}/include/db41

CPPFLAGS+=	-D_REENTRANT ${PTHREAD_CFLAGS} 	\
		-I${LOCALBASE}/include		\
		-I${LOCALBASE}/include/db41

LDFLAGS+=	-L${LOCALBASE}/lib

USE_OPENSSL=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}"	\
		CPPFLAGS="${CPPFLAGS}"	\
		LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS+=--prefix=${PREFIX} 	\
		--enable-bdb		\
		--enable-crypt

.if defined(WITHOUT_SASL)
CONFIGURE_ARGS+=			\
	--without-cyrus-sasl
.else
LIB_DEPENDS+=   sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=			\
	--with-cyrus-sasl		\
	--enable-spasswd
.endif

# ------------------------------------------------------------------------------
# common configure
#
CONFIGURE_ARGS+=			\
	--with-tls              	\
	--localstatedir=/var/db

# Include tcp-wrapper support
.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(CLIENT_ONLY)
# ------------------------------------------------------------------------------
# libraries and client applications only
#
BUILD_CLIENTS=	yes
INSTALLS_SHLIB=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-client
COMMENT=	Open source LDAP client software
CONFIGURE_ARGS+=			\
	--disable-slapd			\
	--disable-slurpd		\
	--enable-shared			\
	--enable-static

.elif defined(SLAPD_ONLY)
# ------------------------------------------------------------------------------
# slapd only
#
BUILD_SLAPD=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-slapd
COMMENT=	Open source LDAP server software (slapd only)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap-client2.1
CONFIGURE_ARGS+=			\
	--enable-slapd			\
	--disable-slurpd		\
	--disable-shared		\
	--disable-static		\
	--without-threads          	\
	--enable-ldbm			\
	--enable-ldap          		\
	--enable-shell

.elif defined(SLURPD_ONLY)
# ------------------------------------------------------------------------------
# slurpd only
# NOTE: to build slurpd only package we have to build slapd
# and some backend we just don't install them later on
#
BUILD_SLURPD=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-slurpd
COMMENT=	Open source LDAP server software (slurpd only)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap-client2.1
RUN_DEPENDS+=	${LOCALBASE}/libexec/slapd:${PORTSDIR}/net/openldap-slapd2.1
CONFIGURE_ARGS+=			\
	--enable-slurpd			\
	--enable-slapd			\
	--disable-shared		\
	--disable-static		\
	--enable-ldbm			\
	--disable-ldap			\
	--disable-shell			\
	--with-threads

.elif defined(SERVERS_ONLY)
# ------------------------------------------------------------------------------
# slapd and slurpd
#
BUILD_SLAPD=	yes
BUILD_SLURPD=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-server
COMMENT=	Open source LDAP server software (slapd and slurpd)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap-client2.1
CONFIGURE_ARGS+=			\
	--enable-slapd			\
	--enable-slurpd			\
	--disable-shared		\
	--disable-static		\
	--with-threads			\
	--enable-ldbm			\
	--disable-ldap          	\
	--disable-shell

.else
# ------------------------------------------------------------------------------
#
# full package
#
INSTALLS_SHLIB=	yes
BUILD_CLIENTS=	yes
BUILD_SLAPD=	yes
BUILD_SLURPD=	yes
CONFIGURE_ARGS+=			\
	--with-threads          	\
	--enable-slapd			\
	--enable-slurpd         	\
	--enable-ldbm			\
	--enable-ldap          		\
	--enable-shell			\
	--enable-shared			\
	--enable-static

.endif

# ------------------------------------------------------------------------------
# PLIST subs and MAN?/MLINKS
#
.if defined(BUILD_CLIENTS)
PLIST_SUB+=	NO_CLIENTS=
MAN1+=	ldapcompare.1
MAN1+=	ldapdelete.1
MAN1+=	ldapmodify.1
MLINKS+=	ldapmodify.1 ldapadd.1
MAN1+=	ldapmodrdn.1
MAN1+=	ldappasswd.1
MAN1+=	ldapsearch.1
MAN1+=	ldapwhoami.1
MAN3+=	lber-decode.3
MLINKS+=	lber-decode.3 ber_get_next.3
MLINKS+=	lber-decode.3 ber_skip_tag.3
MLINKS+=	lber-decode.3 ber_peek_tag.3
MLINKS+=	lber-decode.3 ber_scanf.3
MLINKS+=	lber-decode.3 ber_get_int.3
MLINKS+=	lber-decode.3 ber_get_enum.3
MLINKS+=	lber-decode.3 ber_get_stringb.3
MLINKS+=	lber-decode.3 ber_get_stringa.3
MLINKS+=	lber-decode.3 ber_get_stringal.3
MLINKS+=	lber-decode.3 ber_get_stringbv.3
MLINKS+=	lber-decode.3 ber_get_null.3
MLINKS+=	lber-decode.3 ber_get_boolean.3
MLINKS+=	lber-decode.3 ber_get_bitstring.3
MLINKS+=	lber-decode.3 ber_first_element.3
MLINKS+=	lber-decode.3 ber_next_element.3
MAN3+=	lber-encode.3
MLINKS+=	lber-encode.3 ber_alloc_t.3
MLINKS+=	lber-encode.3 ber_flush.3
MLINKS+=	lber-encode.3 ber_printf.3
MLINKS+=	lber-encode.3 ber_put_int.3
MLINKS+=	lber-encode.3 ber_put_enum.3
MLINKS+=	lber-encode.3 ber_put_ostring.3
MLINKS+=	lber-encode.3 ber_put_string.3
MLINKS+=	lber-encode.3 ber_put_null.3
MLINKS+=	lber-encode.3 ber_put_boolean.3
MLINKS+=	lber-encode.3 ber_put_bitstring.3
MLINKS+=	lber-encode.3 ber_start_seq.3
MLINKS+=	lber-encode.3 ber_start_set.3
MLINKS+=	lber-encode.3 ber_put_seq.3
MLINKS+=	lber-encode.3 ber_put_set.3
MAN3+=	lber-memory.3
MLINKS+=	lber-memory.3 ber_memalloc.3
MLINKS+=	lber-memory.3 ber_memcalloc.3
MLINKS+=	lber-memory.3 ber_memrealloc.3
MLINKS+=	lber-memory.3 ber_memfree.3
MLINKS+=	lber-memory.3 ber_memvfree.3
MAN3+=	lber-types.3
MLINKS+=	lber-types.3 ber_int_t.3
MLINKS+=	lber-types.3 ber_uint_t.3
MLINKS+=	lber-types.3 ber_len_t.3
MLINKS+=	lber-types.3 ber_slen_t.3
MLINKS+=	lber-types.3 ber_tag_t.3
MAN3+=	ldap.3
MAN3+=	ldap_abandon.3
MLINKS+=	ldap_abandon.3 ldap_abandon_ext.3
MAN3+=	ldap_add.3
MLINKS+=	ldap_add.3 ldap_add_s.3
MLINKS+=	ldap_add.3 ldap_add_ext.3
MLINKS+=	ldap_add.3 ldap_add_ext_s.3
MAN3+=	ldap_bind.3
MLINKS+=	ldap_bind.3 ldap_bind_s.3
MLINKS+=	ldap_bind.3 ldap_simple_bind.3
MLINKS+=	ldap_bind.3 ldap_simple_bind_s.3
MLINKS+=	ldap_bind.3 ldap_kerberos_bind_s.3
MLINKS+=	ldap_bind.3 ldap_kerberos_bind1.3
MLINKS+=	ldap_bind.3 ldap_kerberos_bind1_s.3
MLINKS+=	ldap_bind.3 ldap_kerberos_bind2.3
MLINKS+=	ldap_bind.3 ldap_kerberos_bind2_s.3
MLINKS+=	ldap_bind.3 ldap_sasl_bind.3
MLINKS+=	ldap_bind.3 ldap_sasl_bind_s.3
MLINKS+=	ldap_bind.3 ldap_sasl_interactive_bind_s.3
MLINKS+=	ldap_bind.3 ldap_unbind.3
MLINKS+=	ldap_bind.3 ldap_unbind_s.3
MLINKS+=	ldap_bind.3 ldap_unbind_ext.3
MLINKS+=	ldap_bind.3 ldap_unbind_ext_s.3
MLINKS+=	ldap_bind.3 ldap_set_rebind_proc.3
MAN3+=	ldap_compare.3
MLINKS+=	ldap_compare.3 ldap_compare_s.3
MLINKS+=	ldap_compare.3 ldap_compare_ext.3
MLINKS+=	ldap_compare.3 ldap_compare_ext_s.3
MAN3+=	ldap_delete.3
MLINKS+=	ldap_delete.3 ldap_delete_s.3
MLINKS+=	ldap_delete.3 ldap_delete_ext.3
MLINKS+=	ldap_delete.3 ldap_delete_ext_s.3
MAN3+=	ldap_error.3
MLINKS+=	ldap_error.3 ldap_perror.3
MLINKS+=	ldap_error.3 ld_errno.3
MLINKS+=	ldap_error.3 ldap_result2error.3
MLINKS+=	ldap_error.3 ldap_errlist.3
MLINKS+=	ldap_error.3 ldap_err2string.3
MAN3+=	ldap_first_attribute.3
MLINKS+=	ldap_first_attribute.3 ldap_next_attribute.3
MAN3+=	ldap_first_entry.3
MLINKS+=	ldap_first_entry.3 ldap_next_entry.3
MLINKS+=	ldap_first_entry.3 ldap_count_entries.3
MAN3+=	ldap_first_message.3
MLINKS+=	ldap_first_message.3 ldap_next_message.3
MLINKS+=	ldap_first_message.3 ldap_count_messages.3
MAN3+=	ldap_first_reference.3
MLINKS+=	ldap_first_reference.3 ldap_next_reference.3
MLINKS+=	ldap_first_reference.3 ldap_count_references.3
MAN3+=	ldap_get_dn.3
MLINKS+=	ldap_get_dn.3 ldap_explode_dn.3
MLINKS+=	ldap_get_dn.3 ldap_explode_rdn.3
MLINKS+=	ldap_get_dn.3 ldap_dn2ufn.3
MLINKS+=	ldap_get_dn.3 ldap_str2dn.3
MLINKS+=	ldap_get_dn.3 ldap_dn2str.3
MLINKS+=	ldap_get_dn.3 ldap_dn2dcedn.3
MLINKS+=	ldap_get_dn.3 ldap_dcedn2dn.3
MLINKS+=	ldap_get_dn.3 ldap_dn2ad_canonical.3
MAN3+=	ldap_get_values.3
MLINKS+=	ldap_get_values.3 ldap_get_values_len.3
MLINKS+=	ldap_get_values.3 ldap_count_values.3
MLINKS+=	ldap_get_values.3 ldap_count_values_len.3
MLINKS+=	ldap_get_values.3 ldap_value_free.3
MLINKS+=	ldap_get_values.3 ldap_value_free_len.3
MAN3+=	ldap_modify.3
MLINKS+=	ldap_modify.3 ldap_modify_s.3
MLINKS+=	ldap_modify.3 ldap_modify_ext.3
MLINKS+=	ldap_modify.3 ldap_modify_ext_s.3
MLINKS+=	ldap_modify.3 ldap_mods_free.3
MAN3+=	ldap_open.3
MLINKS+=	ldap_open.3 ldap_init.3
MAN3+=	ldap_modrdn.3
MLINKS+=	ldap_modrdn.3 ldap_modrdn_s.3
MLINKS+=	ldap_modrdn.3 ldap_modrdn2.3
MLINKS+=	ldap_modrdn.3 ldap_modrdn2_s.3
MAN3+=	ldap_parse_reference.3
MAN3+=	ldap_parse_result.3
MLINKS+=	ldap_parse_result.3 ldap_parse_sasl_bind_result.3
MLINKS+=	ldap_parse_result.3 ldap_parse_extended_result.3
MAN3+=	ldap_result.3
MLINKS+=	ldap_result.3 ldap_msgfree.3
MLINKS+=	ldap_result.3 ldap_msgtype.3
MLINKS+=	ldap_result.3 ldap_msgid.3
MAN3+=	ldap_schema.3
MLINKS+=	ldap_schema.3 ldap_str2syntax.3
MLINKS+=	ldap_schema.3 ldap_syntax2str.3
MLINKS+=	ldap_schema.3 ldap_syntax2name.3
MLINKS+=	ldap_schema.3 ldap_syntax_free.3
MLINKS+=	ldap_schema.3 ldap_str2matchingrule.3
MLINKS+=	ldap_schema.3 ldap_matchingrule2str.3
MLINKS+=	ldap_schema.3 ldap_matchingrule2name.3
MLINKS+=	ldap_schema.3 ldap_matchingrule_free.3
MLINKS+=	ldap_schema.3 ldap_str2attributetype.3
MLINKS+=	ldap_schema.3 ldap_attributetype2str.3
MLINKS+=	ldap_schema.3 ldap_attributetype2name.3
MLINKS+=	ldap_schema.3 ldap_attributetype_free.3
MLINKS+=	ldap_schema.3 ldap_str2objectclass.3
MLINKS+=	ldap_schema.3 ldap_objectclass2str.3
MLINKS+=	ldap_schema.3 ldap_objectclass2name.3
MLINKS+=	ldap_schema.3 ldap_objectclass_free.3
MLINKS+=	ldap_schema.3 ldap_scherr2str.3
MAN3+=	ldap_search.3
MLINKS+=	ldap_search.3 ldap_search_s.3
MLINKS+=	ldap_search.3 ldap_search_st.3
MLINKS+=	ldap_search.3 ldap_search_ext.3
MLINKS+=	ldap_search.3 ldap_search_ext_s.3
MAN3+=	ldap_sort.3
MLINKS+=	ldap_sort.3 ldap_sort_entries.3
MLINKS+=	ldap_sort.3 ldap_sort_values.3
MLINKS+=	ldap_sort.3 ldap_sort_strcasecmp.3
MAN3+=	ldap_url.3
MLINKS+=	ldap_url.3 ldap_is_ldap_url.3
MLINKS+=	ldap_url.3 ldap_url_parse.3
MLINKS+=	ldap_url.3 ldap_free_urldesc.3
.else
PLIST_SUB+=	NO_CLIENTS="@comment "
.endif
.if defined(BUILD_SLAPD)
PLIST_SUB+=	NO_SLAPD=
MAN5+=	ldap.conf.5
MAN5+=	ldif.5
MAN5+=	slapd-bdb.5
MAN5+=	slapd-dnssrv.5
MAN5+=	slapd-ldap.5
MAN5+=	slapd-ldbm.5
MAN5+=	slapd-meta.5
MAN5+=	slapd-null.5
MAN5+=	slapd-passwd.5
MAN5+=	slapd-perl.5
MAN5+=	slapd-shell.5
MAN5+=	slapd-sql.5
MAN5+=	slapd-tcl.5
MAN5+=	slapd.access.5
MAN5+=	slapd.conf.5
MAN5+=	slapd.replog.5
MAN8+=	slapadd.8
MAN8+=	slapcat.8
MAN8+=	slapd.8
MAN8+=	slapindex.8
MAN8+=	slappasswd.8
.else
PLIST_SUB+=	NO_SLAPD="@comment "
.endif
.if defined(BUILD_SLURPD)
PLIST_SUB+=	NO_SLUPRD=""
MAN8+=	slurpd.8
.else
PLIST_SUB+=	NO_SLUPRD="@comment "
.endif

post-patch:
	@${CP} ${WRKSRC}/servers/slapd/slapd.conf \
		${WRKSRC}/servers/slapd/slapd.conf.Dist
	@${SED} -e '/^pidfile/s#%LOCALSTATEDIR%#/var/run/ldap#' \
		-e '/^argsfile/s#%LOCALSTATEDIR%#/var/run/ldap#' \
		${WRKSRC}/servers/slapd/slapd.conf.Dist > \
		${WRKSRC}/servers/slapd/slapd.conf

post-build:
.if defined(BUILD_SLAPD)
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/slapd.sh >${WRKDIR}/slapd.sh
.endif
.if defined(BUILD_SLURPD)
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/slurpd.sh >${WRKDIR}/slurpd.sh
.endif

do-install:
.if defined(BUILD_CLIENTS) && defined (BUILD_SLAPD) && defined (BUILD_SLURPD)
	@cd ${WRKSRC} && ${MAKE} install
	@${STRIP_CMD} ${PREFIX}/libexec/slapd
	@${STRIP_CMD} ${PREFIX}/libexec/slurpd
.else
.if defined(BUILD_CLIENTS)
	@cd ${WRKSRC}/include && ${MAKE} install
	@cd ${WRKSRC}/clients && ${MAKE} install
	@cd ${WRKSRC}/libraries && ${MAKE} install
.for i in 1 3
	@cd ${WRKSRC}/doc/man/man$i && ${MAKE} install
.endfor
.endif
.if defined(BUILD_SLAPD)
	@cd ${WRKSRC}/servers/slapd && ${MAKE} install
	@cd ${WRKSRC}/doc/man/man5 && ${MAKE} install
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slapadd.8 ${MANPREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slapcat.8 ${MANPREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slapd.8 ${MANPREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slapindex.8 ${MANPREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slappasswd.8 ${MANPREFIX}/man/man8
	@${MKDIR} ${PREFIX}/libexec
	@${MKDIR} /var/db
	@${STRIP_CMD} ${PREFIX}/libexec/slapd
.endif
.if defined(BUILD_SLURPD)
	@cd ${WRKSRC}/servers/slurpd && ${MAKE} install
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man8/slurpd.8 ${MANPREFIX}/man/man8
	@${MKDIR} ${PREFIX}/libexec
	@${INSTALL_TARGET} -c -o root -g wheel -m 700 -d /var/db/openldap-slurp
	@${STRIP_CMD} ${PREFIX}/libexec/slurpd
.endif
.endif

post-install:
.if defined(BUILD_SLAPD)
	@${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh ${PREFIX}/etc/rc.d/slapd.sh.sample
.endif
.if defined(BUILD_SLURPD)
	@${INSTALL_SCRIPT} ${WRKDIR}/slurpd.sh ${PREFIX}/etc/rc.d/slurpd.sh.sample
.endif

.include <bsd.port.post.mk>
