# New ports collection makefile for:	openwebmail
# Date created:				24 April 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	openwebmail
PORTVERSION?=	2.51
CATEGORIES=	mail
MASTER_SITES=	http://openwebmail.org/openwebmail/download/%SUBDIR%/ \
		http://turtle.ee.ncku.edu.tw/openwebmail/download/%SUBDIR%/
MASTER_SITE_SUBDIR?=	release

MAINTAINER?=	leeym@FreeBSD.org
COMMENT=	A webmail system designed to manage big mail folder files efficiently

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

CONFLICTS?=	${PORTNAME}-devel-[0-9]*

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR=	${PREFIX}/www/cgi-bin/openwebmail
OWDATADIR=	${PREFIX}/www/data/openwebmail
PATCH_WRKSRC=	${WRKSRC}/cgi-bin/openwebmail
PATCH_STRIP=	-p1
PLIST=		${WRKDIR}/.PLIST.${PKGNAME}

OPTIONS=	ANTIWORD "AntiWord" off \
		IMAGEMAGICK "ImageMagicK" off \
		ISPELL "ISpell" off \
		LEARNSPAM "Learn HAM/SPAM" off \
		LSOF "lsof" off \
		PAM "PAM" off \
		POP3_OVER_SSL "POP3 Over SSL" off \
		QUOTA "Quota" off \
		SPAMCHECK "Spam check (Mail::SpamAssassin)" off \
		SPAMCHECK_ALL "Spam check for all (default: pop3)" off \
		SPEEDYCGI "SpeedyCGI" off \
		TNEF "tnef" off \
		VIRUSCHECK "Virus check (Clam AntiVirus)" off \
		VIRUSCHECK_ALL "Virus check for all (default: pop3)" off \
		WGET "wget" off \
		ZLIB "ZLib" off

.include <bsd.port.pre.mk>

# WITH_SPEEDYCGI needs suidperl enabled under perl 5.8.4 or above,
# so, disable it first, and enable it again if perl exists and enabled suidperl
.if ${PERL_LEVEL} >= 500804 && defined(WITH_SPEEDYCGI)
DISABLE_SPEEDYCGI=yes
WITHOUT_SPEEDYCGI=yes
.undef WITH_SPEEDYCGI
.if exists(${PERL})
PERL_V!=	${PERL} -V
.if ${PERL_V:M*dosuid*} != ""
.undef DISABLE_SPEEDYCGI
.undef WITHOUT_SPEEDYCGI
WITH_SPEEDYCGI=	yes
.endif # dosuid
.endif # exists(${PERL})
.endif # perl5.8

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
.endif

.if defined(WITH_LEARNSPAM) || defined(WITH_SPAMCHECK_ALL)
WITH_SPAMCHECK=	true
.endif

.if defined(WITH_VIRUSCHECK_ALL)
WITH_VIRUSCHECK=true
.endif

.if defined(WITH_ANTIWORD)
RUN_DEPENDS+=	antiword:${PORTSDIR}/textproc/antiword
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_LSOF)
RUN_DEPENDS+	${LOCALBASE}/sbin/lsof:${PORTSDIR}/sysutils/lsof
.endif

.if defined(WITH_PAM)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM
.endif

.if defined(WITH_POP3_OVER_SSL)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if defined(WITH_QUOTA)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota
.endif

.if defined(WITH_TNEF)
RUN_DEPENDS+=	${LOCALBASE}/bin/tnef:${PORTSDIR}/converters/tnef
.endif

.if defined(WITH_SPAMCHECK)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(WITH_SPEEDYCGI)
RUN_DEPENDS+=	speedy_suidperl:${PORTSDIR}/www/p5-CGI-SpeedyCGI
.if ${PERL_LEVEL} < 500804
EXTRA_PATCHES+=	${PATCH_WRKSRC}/misc/patches/suidperl2speedy_suidperl.patch
.else
EXTRA_PATCHES+=	${PATCH_WRKSRC}/misc/patches/suidperl2speedy_suidperl.notmp.patch
.endif
.endif

.if defined(WITH_VIRUSCHECK)
RUN_DEPENDS+=	clamdscan:${PORTSDIR}/security/clamav
.endif

.if defined(WITH_WGET)
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
.endif

.if defined(WITH_ZLIB)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

post-extract:
.for x in addressbooks/global calendar.book
	@${RM} ${WRKSRC}/cgi-bin/openwebmail/etc/${x}
.endfor

post-patch:
.if defined(DISABLE_SPEEDYCGI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WARNING:"
	@${ECHO_MSG} "Your perl doesn't support SUID, or you don't have perl yet,"
	@${ECHO_MSG} "so SpeedyCGI support is disabled automatically."
	@${ECHO_MSG} "If you want SpeedyCGI support, please reinstall perl with ENABLE_SUIDPERL=yes,"
	@${ECHO_MSG} "and reinstall ${PORTNAME}."
	@${ECHO_MSG} ""
.endif
	@${MV} ${PATCH_WRKSRC}/etc/openwebmail.conf ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/cgi-bin/openwebmail,${OWCGIDIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/data/openwebmail,${OWDATADIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.if defined(WITH_LEARNSPAM)
	@${PERL} -pi.bak -e 's,enable_learnspam	no,enable_learnspam	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.endif
.if defined(WITH_SPAMCHECK)
	@${PERL} -pi.bak -e 's,enable_spamcheck	no,enable_spamcheck	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
	@${ECHO} "enable_saprefs	yes" >> ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.endif
.if defined(WITH_SPAMCHECK_ALL)
	@${ECHO} "spamcheck_source_allowed	all" >> ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.endif
.if defined(WITH_VIRUSCHECK)
	@${PERL} -pi.bak -e 's,enable_viruscheck	no,enable_viruscheck	yes,g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.endif
.if defined(WITH_VIRUSCHECK_ALL)
	@${ECHO} "viruscheck_source_allowed	all" >> ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.endif
.if defined(WITH_SPEEDYCGI)
	@${ECHO} "has_savedsuid_support	no" >> ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.else
	@${PERL} -pi.bak -e 's,/usr/bin/suidperl,${PERL},g' ${PATCH_WRKSRC}/openwebmail*pl
.endif

pre-install:
	@${FIND} ${WRKSRC}/*/openwebmail \( -name "*.bak" -or -name "*.orig" \) -delete
.if !exists(${PLIST})
	@${ECHO} "@unexec if cmp -s %D/www/cgi-bin/openwebmail/etc/openwebmail.conf %D/www/cgi-bin/openwebmail/etc/openwebmail.conf-dist; then ${RM} -f %D/www/cgi-bin/openwebmail/etc/openwebmail.conf; fi" > ${PLIST}
	@${FIND} ${WRKSRC}/*/openwebmail -type f -o -type l | \
		${SED} -e 's,${WRKSRC},www,g' | ${SORT} -u >> ${PLIST}
	@${ECHO} "www/cgi-bin/openwebmail/etc/dbm.conf" >> ${PLIST}
.for f in b2g g2b lunar
	@${ECHO} "www/cgi-bin/openwebmail/etc/maps/${f}.db" >> ${PLIST}
.endfor
.if defined(WITHOUT_SPEEDYCGI)
	@${FIND} ${WRKSRC}/*/openwebmail -name "openwebmail*pl" | \
		${SED} -e 's,${WRKSRC},www,g' \
		-e 's,openwebmail/openwebmail,openwebmail/.openwebmail,g' \
		>> ${PLIST}
.endif
	@${FIND} ${WRKSRC}/*/openwebmail -type d | ${SORT} -ur | \
		${SED} -e 's,${WRKSRC},@dirrm www,g' >> ${PLIST}
.endif

do-install:
	@${MKDIR} ${OWCGIDIR} ${OWDATADIR}
	@cd ${WRKSRC}/cgi-bin/openwebmail && ${FIND} . \
		| ${CPIO} -dpum --quiet -R ${BINOWN}:mail ${OWCGIDIR}
	@cd ${WRKSRC}/data/openwebmail && ${FIND} . \
		| ${CPIO} -dpum --quiet -R ${SHAREOWN}:${SHAREGRP} ${OWDATADIR}
.if !exists(${OWCGIDIR}/etc/openwebmail.conf)
	@${CP} ${OWCGIDIR}/etc/openwebmail.conf-dist ${OWCGIDIR}/etc/openwebmail.conf
.endif
	@${PERL} ${OWCGIDIR}/misc/test/dbmtest.pl | ${GREP} "^dbm" > ${OWCGIDIR}/etc/dbm.conf
	@${CHMOD} 4755 ${OWCGIDIR}/openwebmail*pl
.if defined(WITHOUT_SPEEDYCGI)
	@${PERL} ${OWCGIDIR}/misc/tools/wrapsuid/wrapsuid.pl ${OWCGIDIR} 2>/dev/null
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
