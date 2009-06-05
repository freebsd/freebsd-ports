# New ports collection makefile for:	dkim-milter
# Date created:				10 Jan 2006
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#
## There is a new option WITH_POSTFIX_MILTER
## to make this port work with mail/postfix port.

## WITH_POSTFIX_MILTER knob implicitly defines
## WITH_SENDMAIL_BASE, to build with libmilter*
## in base system.  If you have deleted sendamil in
## base system, building this port may fail.

PORTNAME=	dkim-milter
PORTVERSION=	2.8.3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Domainkeys Identified Mail (DKIM) milter

USE_RC_SUBR=	milter-dkim.sh
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

.if defined(WITH_POSTFIX) || defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX_CURRENT)
WITH_SENDMAIL_BASE=	yes
PKGMESSAGE=	${PKGDIR}/pkg-message.postfix

.if defined(SENDMAIL_MILTER_IN_BASE)
WITH_SENDMAIL_BASE=yes
.endif

.if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.endif
.endif

SUB_FILES=	milter-dkim.sh
WCONF=		${WRKSRC}/devtools/Site
MAN5=		dkim-filter.conf.5
MAN8=		dkim-filter.8 dkim-genkey.8 dkim-testkey.8 dkim-testssp.8
PLIST_FILES=	etc/mail/dkim-filter.conf.sample include/dkim.h \
		bin/dkim-genkey %%STATS%%bin/dkim-stats bin/dkim-testkey \
		bin/dkim-testssp %%ARLIB%%lib/libar.a %%LIBDKIM%%lib/libdkim.a \
		%%LIBDKIMSHARED%%lib/libdkim.so %%LIBDKIMSHARED%%lib/libdkim.so.0 \
		libexec/dkim-filter
PLIST_DIRS=	etc/mail
PORTDOCS=	FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		autorespond.csh \
		draft-ietf-dkim-deployment-04.txt draft-ietf-dkim-overview-12.txt \
		draft-ietf-dkim-rfc4871-errata-05.txt draft-ietf-dkim-ssp-10.txt \
		draft-kucherawy-dkim-reporting-04.txt draft-shafranovich-feedback-report-07.txt \
		rfc4686.txt rfc4871.txt rfc5016.txt rfc5451.txt rfc5518.txt
.if !defined(NOPORTDOCS)
LIBDOCS=	${DOCSDIR_REL}/libdkim/index.html \
		${DOCSDIR_REL}/libdkim/overview.html \
		${DOCSDIR_REL}/libdkim/dkim.html \
		${DOCSDIR_REL}/libdkim/dkim_alg_t.html \
		${DOCSDIR_REL}/libdkim/dkim_body.html \
		${DOCSDIR_REL}/libdkim/dkim_canon_t.html \
		${DOCSDIR_REL}/libdkim/dkim_cbstat.html \
		${DOCSDIR_REL}/libdkim/dkim_chunk.html \
		${DOCSDIR_REL}/libdkim/dkim_close.html \
		${DOCSDIR_REL}/libdkim/dkim_dnssec.html \
		${DOCSDIR_REL}/libdkim/dkim_eoh.html \
		${DOCSDIR_REL}/libdkim/dkim_eom.html \
		${DOCSDIR_REL}/libdkim/dkim_flush_cache.html \
		${DOCSDIR_REL}/libdkim/dkim_free.html \
		${DOCSDIR_REL}/libdkim/dkim_get_user_context.html \
		${DOCSDIR_REL}/libdkim/dkim_getcachestats.html \
		${DOCSDIR_REL}/libdkim/dkim_getdomain.html \
		${DOCSDIR_REL}/libdkim/dkim_geterror.html \
		${DOCSDIR_REL}/libdkim/dkim_getmode.html \
		${DOCSDIR_REL}/libdkim/dkim_getpolicystr.html \
		${DOCSDIR_REL}/libdkim/dkim_getpresult.html \
		${DOCSDIR_REL}/libdkim/dkim_getpresultstr.html \
		${DOCSDIR_REL}/libdkim/dkim_getresultstr.html \
		${DOCSDIR_REL}/libdkim/dkim_getsighdr.html \
		${DOCSDIR_REL}/libdkim/dkim_getsiglist.html \
		${DOCSDIR_REL}/libdkim/dkim_getsignature.html \
		${DOCSDIR_REL}/libdkim/dkim_header.html \
		${DOCSDIR_REL}/libdkim/dkim_init.html \
		${DOCSDIR_REL}/libdkim/dkim_key_syntax.html \
		${DOCSDIR_REL}/libdkim/dkim_lib.html \
		${DOCSDIR_REL}/libdkim/dkim_minbody.html \
		${DOCSDIR_REL}/libdkim/dkim_ohdrs.html \
		${DOCSDIR_REL}/libdkim/dkim_options.html \
		${DOCSDIR_REL}/libdkim/dkim_param_t.html \
		${DOCSDIR_REL}/libdkim/dkim_policy.html \
		${DOCSDIR_REL}/libdkim/dkim_policy_getdnssec.html \
		${DOCSDIR_REL}/libdkim/dkim_policy_getreportinfo.html \
		${DOCSDIR_REL}/libdkim/dkim_policy_syntax.html \
		${DOCSDIR_REL}/libdkim/dkim_policy_t.html \
		${DOCSDIR_REL}/libdkim/dkim_presult.html \
		${DOCSDIR_REL}/libdkim/dkim_pstate.html \
		${DOCSDIR_REL}/libdkim/dkim_query_t.html \
		${DOCSDIR_REL}/libdkim/dkim_set_dns_callback.html \
		${DOCSDIR_REL}/libdkim/dkim_set_final.html \
		${DOCSDIR_REL}/libdkim/dkim_set_key_lookup.html \
		${DOCSDIR_REL}/libdkim/dkim_set_margin.html \
		${DOCSDIR_REL}/libdkim/dkim_set_policy_lookup.html \
		${DOCSDIR_REL}/libdkim/dkim_set_prescreen.html \
		${DOCSDIR_REL}/libdkim/dkim_set_signature_handle.html \
		${DOCSDIR_REL}/libdkim/dkim_set_signature_handle_free.html \
		${DOCSDIR_REL}/libdkim/dkim_set_signature_tagvalues.html \
		${DOCSDIR_REL}/libdkim/dkim_set_signer.html \
		${DOCSDIR_REL}/libdkim/dkim_set_user_context.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getbh.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getcanonlen.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getcontext.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getdnssec.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getdomain.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_geterror.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_geterrorstr.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getflags.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getkeysize.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getreportinfo.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getselector.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getsignalg.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_getsigntime.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_hdrsigned.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_ignore.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_process.html \
		${DOCSDIR_REL}/libdkim/dkim_sig_syntax.html \
		${DOCSDIR_REL}/libdkim/dkim_sigerror.html \
		${DOCSDIR_REL}/libdkim/dkim_siginfo.html \
		${DOCSDIR_REL}/libdkim/dkim_sigkey_t.html \
		${DOCSDIR_REL}/libdkim/dkim_sign.html \
		${DOCSDIR_REL}/libdkim/dkim_ssl_version.html \
		${DOCSDIR_REL}/libdkim/dkim_stat.html \
		${DOCSDIR_REL}/libdkim/dkim_verify.html \
		${DOCSDIR_REL}/libdkim/rfc2822_mailbox_split.html
PLIST_FILES+=	${DOCSDIR_REL}/README.dkim-filter \
		${DOCSDIR_REL}/README.libdkim \
		${LIBDOCS}
PLIST_DIRS+=	${DOCSDIR_REL}/libdkim
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ARLIB) && !(defined(WITH_UNBOUND) && !defined(WITHOUT_UNBOUND))
WITH_ARLIB=	yes
.endif

.if ${OSVERSION} < 700000
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"

WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

SITE+=		${FILESDIR}/site.config.m4
.if defined(WITH_SENDMAIL_PORT)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif
SITE+=		${WRKSRC}/site.config.m4.dist
SITE_SUB+=	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"
.if defined(WITH_SENDMAIL_STATIC_MILTER)
SITE_SUB+=	-e 's|%%STATIC%%||g'
.else
SITE_SUB+=	-e 's|%%STATIC%%|dnl |g'
.endif

SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR:S/.sh$//}${RC_SUBR_SUFFIX}"

.if defined(WITH_LIBDKIM_SHARED)
PLIST_SUB+=	LIBDKIM=""
PLIST_SUB+=	LIBDKIMSHARED=""
SITE_SUB+=	-e '\|bld_LIBDKIM_SHARED|s/^dnl //g'
USE_LDCONFIG=	yes
.if defined(WITH_ARLIB)
PLIST_SUB+=	ARLIB=""
.else
PLIST_SUB+=	ARLIB="@comment "
.endif
.else
PLIST_SUB+=	LIBDKIMSHARED="@comment "
.endif
.if defined(WITH_LIBDKIM_INSTALL)
SITE_SUB+=	-e '\|bld_LIBDKIM_INSTALL|s/^dnl //g'
PLIST_SUB+=	LIBDKIM=""
.if defined(WITH_ARLIB)
PLIST_SUB+=	ARLIB=""
.else
PLIST_SUB+=	ARLIB="@comment "
.endif
.endif
.if !defined(WITH_LIBDKIM_INSTALL) && !defined(WITH_LIBDKIM_SHARED)
PLIST_SUB+=	LIBDKIM="@comment "
PLIST_SUB+=	ARLIB="@comment "
.endif
.if defined(WITH_DEBUG)
SITE_SUB+=	-e '\|confOPTIMIZE.*-g|s/^dnl //g'
.endif
.if defined(WITH_UNBOUND) && !defined(WITHOUT_UNBOUND)
.if defined(WITH_ARLIB)
IGNORE=		libar cannot be used simultaneously with libunbound
.endif
LIB_DEPENDS+=	unbound:${PORTSDIR}/dns/unbound
SITE_SUB+=	-e 's|%%UNBOUND%%||g' \
		-e '\|bld_USE_UNBOUND.*true|s/^dnl //g'
.else
SITE_SUB+=	-e 's|%%UNBOUND%%|dnl |g'
.if !defined(WITHOUT_ARLIB)
SITE_SUB+=	-e '\|bld_USE_ARLIB.*true|s/^dnl //g'
.endif
.endif
.if defined(WITH_POPAUTH) && !defined(WITHOUT_POPAUTH)
SITE_SUB+=	-e '/-DPOPAUTH/s/^dnl //g'
.endif
.if defined(WITH_QUERY_CACHE) && !defined(WITHOUT_QUERY_CACHE)
SITE_SUB+=	-e '/-DQUERY_CACHE/s/^dnl //g'
.endif

.if defined(WITH_VERIFY_DOMAINKEYS) && !defined(WITHOUT_VERIFY_DOMAINKEYS)
LIBDK_PORT=	mail/dk-milter
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${LIBDK_PORT}:patch
LIBDK_PATH_CMD=	cd ${PORTSDIR}/${LIBDK_PORT} && ${MAKE} -V WRKSRC
SITE_SUB+=	-e '\|bld_VERIFY_DOMAINKEYS|s/^dnl //'
PORTDOCS+=	rfc4870.txt
.endif

.if defined(WITH_STATS) && !defined(WITHOUT_STATS)
MAN8+=		dkim-stats.8
PLIST_SUB+=	STATS=""
.else
PLIST_SUB+=	STATS="@comment "
.endif

.if (defined(WITH_POPAUTH) \
	|| defined(WITH_QUERY_CACHE) \
	|| defined(WITH_BODYLENGTH_DB) \
	|| defined(WITH_STATS)) \
	&& !defined(WITH_BDB_BASE)
USE_BDB=	41+
SITE_SUB+=	-e 's|%%BDB%%||g' \
		-e "s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g" \
		-e "s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g" \
		-e "s|%%BDB_LIB_NAME%%|${BDB_LIB_NAME}|g"
.else
SITE_SUB+=	-e 's|%%BDB%%|dnl |g'
.endif
.if defined(WITH_OPENSSL_BASE) || defined(OPENSSL_OVERWRITE_BASE)
SITE_SUB+=	-e 's|%%OPENSSL%%|dnl |g'
.else
SITE_SUB+=	-e 's|%%OPENSSL%%||g' \
		-e "s|%%OPENSSLINC%%|${OPENSSLINC}|g" \
		-e "s|%%OPENSSLLIB%%|${OPENSSLLIB}|g"
.endif
.if defined(WITH_DIFFHEADERS) && !defined(WITHOUT_DIFFHEADERS)
SITE_SUB+=	-e 's|%%LIBTRE%%||g'
LIB_DEPENDS+=	tre:${PORTSDIR}/textproc/libtre
.else
SITE_SUB+=	-e 's|%%LIBTRE%%|dnl |g'
.endif

pre-fetch:
.if defined(SENDMAIL_MILTER_IN_BASE)
	@${ECHO_MSG}
	@${ECHO_MSG} "SENDMAIL_MILTER_IN_BASE now deprecated,"
	@${ECHO_MSG} "please set WITH_SENDMAIL_BASE=yes instead"
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} "dkim-milter has the following tunable option(s):"
	@${ECHO_MSG} " WITH_POPAUTH=yes		Query POP-before-SMTP authentication database"
	@${ECHO_MSG} " WITH_QUERY_CACHE=yes		Cache DNS Query"
	@${ECHO_MSG} " WITH_VERIFY_DOMAINKEYS=yes	Verify DomainKeys using dk-milter's libdk"
	@${ECHO_MSG} " WITH_SENDMAIL_BASE=yes		Build to run with base sendmail"
	@${ECHO_MSG} " WITH_SENDMAIL_PORT=yes		Build to run with ports' sendmail"
	@${ECHO_MSG} " WITH_POSTFIX=yes		Build to run with postfix port"
	@${ECHO_MSG} " WITH_LIBDKIM_INSTALL=yes	Install libdkim library"
	@${ECHO_MSG} " WITH_UNBOUND=yes		Link against libunbound"
	@${ECHO_MSG}

post-extract:
	@${CP} ${WRKSRC}/dkim-filter/autorespond.csh ${WRKSRC}

.include	"${.CURDIR}/Makefile.features"
post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		${WRKSRC}/devtools/OS/FreeBSD
.if !defined(WITHOUT_ARLIB) && (defined(WITH_LIBDKIM_INSTALL) || defined(WITH_LIBDKIM_SHARED)) && !(defined(WITH_UNBOUND) || !defined(WITHOUT_UNBOUND))
	@${REINPLACE_CMD} -e 's|%%ARLIB%%||' ${WRKSRC}/libar/Makefile.m4
.else
	@${REINPLACE_CMD} -e 's|%%ARLIB%%|dnl |' ${WRKSRC}/libar/Makefile.m4
.endif
	@${SED} ${SITE_SUB} -e '\|^dnl |d' -e '/^dnl$$/d' \
		${SITE} > ${WCONF}/site.config.m4

pre-configure:
.if defined(WITH_VERIFY_DOMAINKEYS) && !defined(WITHOUT_VERIFY_DOMAINKEYS)
	${LN} -s $$(${LIBDK_PATH_CMD})/libdk ${WRKSRC}/
	${CP} $$(${LIBDK_PATH_CMD})/rfc4870.txt ${WRKSRC}/
.endif

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/libexec/dkim-filter
.endif
	@${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/dkim-filter.conf.sample ${PREFIX}/etc/mail/
.for i in ${MAN5}
	@${RM} -f ${MANPREFIX}/man/cat5/${i} ${MANPREFIX}/man/cat5/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man5/
.endfor
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/README ${DOCSDIR}/README.dkim-filter
	${INSTALL_DATA} ${WRKSRC}/libdkim/README ${DOCSDIR}/README.libdkim
	${MKDIR} ${DOCSDIR}/libdkim
.for f in ${LIBDOCS}
	${INSTALL_DATA} ${WRKSRC}/libdkim/docs/`${BASENAME} ${f}` ${DOCSDIR}/libdkim/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
