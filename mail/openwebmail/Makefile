# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	openwebmail
PORTVERSION=	2.53
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://openwebmail.acatysmoof.com/download/release/ \
		http://openwebmail.org/openwebmail/download/release/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Webmail system designed to manage big mail folder files efficiently

RUN_DEPENDS=	p5-Text-Iconv>=0:converters/p5-Text-Iconv

USES=		perl5
USE_PERL5=	run build patch
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR=	${PREFIX}/www/cgi-bin/openwebmail
OWDATADIR=	${PREFIX}/www/data/openwebmail
PATCH_WRKSRC=	${WRKSRC}/cgi-bin/openwebmail
PATCH_STRIP=	-p1
PLIST=		${WRKDIR}/.PLIST.${PKGNAME}
SUB_FILES=	pkg-install

PLIST_DIRS=	www/cgi-bin/openwebmail/etc/addressbooks \
		www/cgi-bin/openwebmail/etc/sessions \
		www/cgi-bin/openwebmail/etc/users \
		www/data/openwebmail/help/zh_CN.GB2312/images/_notes \
		www/data/openwebmail/help/zh_CN.GB2312/templates_and_data/_notes

OPTIONS_DEFINE=	ANTIWORD MAGICK ISPELL LEARNSPAM LSOF PAM POP3_OVER_SSL QUOTA \
		SPAMCHECK SPAMCHECK_ALL SPEEDYCGI TNEF VIRUSCHECK VIRUSCHECK_ALL \
		WGET

ANTIWORD_DESC=	AntiWord
ANTIWORD_RUN_DEPENDS=	antiword:textproc/antiword
ISPELL_DESC=	ISpell
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
LEARNSPAM_DESC=	Learn HAM/SPAM
LEARNSPAM_IMPLIES=	SPAMCHECK
LSOF_DESC=	lsof
LSOF_RUN_DEPENDS=	${LOCALBASE}/sbin/lsof:sysutils/lsof
MAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick
PAM_DESC=	PAM
PAM_RUN_DEPENDS=	p5-Authen-PAM>=0:security/p5-Authen-PAM
POP3_OVER_SSL_DESC=	POP3 Over SSL
POP3_OVER_SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
QUOTA_DESC=	Quota
QUOTA_RUN_DEPENDS=	p5-Quota>=0:sysutils/p5-Quota
SPAMCHECK_DESC=	Spam check (Mail::SpamAssassin)
SPAMCHECK_RUN_DEPENDS=	spamassassin>=0:mail/spamassassin
SPAMCHECK_ALL_DESC=	Spam check for all (default: pop3)
SPAMCHECK_ALL_IMPLIES=	SPAMCHECK
SPEEDYCGI_DESC=	SpeedyCGI
SPEEDYCGI_RUN_DEPENDS=	speedy_suidperl:www/p5-CGI-SpeedyCGI
SPEEDYCGI_SUB_LIST=	WITHOUT_SPEEDYCGI="@comment "
SPEEDYCGI_SUB_LIST_OFF=	WITHOUT_SPEEDYCGI=""
SPEEDYCGI_EXTRA_PATCHES=	${PATCH_WRKSRC}/misc/patches/suidperl2speedy_suidperl.notmp.patch
TNEF_DESC=	tnef
TNEF_RUN_DEPENDS=	${LOCALBASE}/bin/tnef:converters/tnef
VIRUSCHECK_DESC=	Virus check (Clam AntiVirus)
VIRUSCHECK_RUN_DEPENDS=	clamdscan:security/clamav
VIRUSCHECK_ALL_DESC=	Virus check for all (default: pop3)
VIRUSCHECK_ALL_IMPLIES=	VIRUSCHECK
WGET_DESC=	wget
WGET_RUN_DEPENDS=	${LOCALBASE}/bin/wget:ftp/wget

.include <bsd.port.pre.mk>

# WITH_SPEEDYCGI needs suidperl enabled under perl 5.8.4 or above,
# so, disable it first, and enable it again if perl exists and enabled suidperl
.if ${PORT_OPTIONS:MSPEEDYCGI}
DISABLE_SPEEDYCGI=yes
PORT_OPTIONS:=	${PORT_OPTIONS:NSPEEDYCGI}
.if exists(${PERL})
PERL_V!=	${PERL} -V
.if ${PERL_V:M*dosuid*} != ""
.undef DISABLE_SPEEDYCGI
.endif # dosuid
.endif # exists(${PERL})
.endif # SPEEDYCGI

post-extract:
.for x in addressbooks/global calendar.book
	@${RM} ${WRKSRC}/cgi-bin/openwebmail/etc/${x}
.endfor

post-patch:
#	### XXX: Hack, some of this should be LOCALBASE
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g'
.if defined(DISABLE_SPEEDYCGI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WARNING:"
	@${ECHO_MSG} "Your perl doesn't support SUID, or you don't have perl yet,"
	@${ECHO_MSG} "so SpeedyCGI support is disabled automatically."
	@${ECHO_MSG} "If you want SpeedyCGI support, please reinstall perl with ENABLE_SUIDPERL=yes,"
	@${ECHO_MSG} "and reinstall ${PORTNAME}."
	@${ECHO_MSG} ""
.endif
	@${MV} ${PATCH_WRKSRC}/etc/openwebmail.conf ${PATCH_WRKSRC}/etc/openwebmail.conf.sample
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/cgi-bin/openwebmail,${OWCGIDIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf.sample
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/data/openwebmail,${OWDATADIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-LEARNSPAM-on:
	@${PERL} -pi.bak -e 's,enable_learnspam	no,enable_learnspam	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-SPAMCHECK-on:
	@${PERL} -pi.bak -e 's,enable_spamcheck	no,enable_spamcheck	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf.sample
	@${ECHO} "enable_saprefs	yes" >> ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-SPAMCHECK_ALL-on:
	@${ECHO} "spamcheck_source_allowed	all" >> ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-VIRUSCHECK-on:
	@${PERL} -pi.bak -e 's,enable_viruscheck	no,enable_viruscheck	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-VIRUSCHECK_ALL-on:
	@${ECHO} "viruscheck_source_allowed	all" >> ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-SPEEDYCGI-on:
	@${ECHO} "has_savedsuid_support	no" >> ${PATCH_WRKSRC}/etc/openwebmail.conf.sample

post-patch-SPEEDYCGI-off:
	@${PERL} -pi.bak -e 's,/usr/bin/suidperl,${PERL},g' ${PATCH_WRKSRC}/openwebmail*pl

pre-install:
	@: > ${PLIST}
	@${FIND} ${WRKSRC}/*/openwebmail \( -name "*.bak" -or -name "*.orig" \) -delete
	@${PRINTF} "%s\n%s\n" "@owner ${BINOWN}" "@group mail" >> ${PLIST}
	@${ECHO} "@sample www/cgi-bin/openwebmail/etc/openwebmail.conf.sample" >> ${PLIST}
	@${FIND} ${WRKSRC}/cgi-bin/openwebmail \( -type f -o -type l \) -and -not -name openwebmail.conf.sample | \
		${SED} -e 's,^${WRKSRC},www,' | ${SORT} -u >> ${PLIST}
	@${ECHO} "www/cgi-bin/openwebmail/etc/dbm.conf" >> ${PLIST}
	@${PRINTF} "%s\n%s\n" "@owner" "@group" >> ${PLIST}
	@${FIND} ${WRKSRC}/data/openwebmail \( -type f -o -type l \) -and -not -name openwebmail.conf.sample | \
		${SED} -e 's,^${WRKSRC},www,' | ${SORT} -u >> ${PLIST}

pre-install-SPEEDYCGI-off:
	@${FIND} ${WRKSRC}/*/openwebmail -name "openwebmail*pl" | \
		${SED} -e 's,^${WRKSRC},www,' \
		-e 's,openwebmail/openwebmail,openwebmail/.openwebmail,g' \
		>> ${TMPPLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${OWCGIDIR} ${STAGEDIR}${OWDATADIR}
	@(cd ${WRKSRC}/cgi-bin/openwebmail && \
		${COPYTREE_SHARE} . ${STAGEDIR}${OWCGIDIR})
	@(cd ${WRKSRC}/data/openwebmail && \
		${COPYTREE_SHARE} . ${STAGEDIR}${OWDATADIR})
	@${PERL} ${STAGEDIR}${OWCGIDIR}/misc/test/dbmtest.pl | ${GREP} "^dbm" > ${STAGEDIR}${OWCGIDIR}/etc/dbm.conf
	@${CHMOD} 4755 ${STAGEDIR}${OWCGIDIR}/openwebmail*pl

.include <bsd.port.post.mk>
