# New ports collection makefile for:	openwebmail
# Date created:				24 April 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	openwebmail
PORTVERSION=	2.32
CATEGORIES=	mail
MASTER_SITES=	http://openwebmail.org/openwebmail/download/release/ \
		http://turtle.ee.ncku.edu.tw/openwebmail/download/release/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A webmail system designed to manage big mail folder files efficiently

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500802
RUN_DEPENDS+=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
.endif

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR?=	${PREFIX}/www/cgi-bin/openwebmail
OWDATADIR?=	${PREFIX}/www/data/openwebmail
PATCH_WRKSRC=	${WRKSRC}/cgi-bin/openwebmail
PATCH_STRIP=	-p1
PLIST=		${WRKDIR}/.PLIST.${PKGNAME}

.if !defined(WITHOUT_SPEEDYCGI)
BUILD_DEPENDS+=	speedy_suidperl:${PORTSDIR}/www/p5-CGI-SpeedyCGI
RUN_DEPENDS+=	speedy_suidperl:${PORTSDIR}/www/p5-CGI-SpeedyCGI
EXTRA_PATCHES=	${PATCH_WRKSRC}/uty/suidperl2speedy_suid.diff
.else
_CUSTOMIZED=	yes
.endif

.if defined(WITH_PAM)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM
_CUSTOMIZED=	yes
.endif

.if defined(WITH_ZLIB)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
_CUSTOMIZED=	yes
.endif

.if defined(WITH_QUOTA)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota
_CUSTOMIZED=	yes
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
_CUSTOMIZED=	yes
.endif

.if defined(WITH_ANTIWORD)
RUN_DEPENDS+=	antiword:${PORTSDIR}/textproc/antiword
_CUSTOMIZED=	yes
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
_CUSTOMIZED=	yes
.endif

pre-fetch:
.if ${PERL_LEVEL} > 500800
	@${ECHO} ""
	@${ECHO} "WARNING:"
	@${ECHO} "Please make sure that your PERL is built with -DENABLE_SUIDPERL,"
	@${ECHO} "otherwise please build openwebmail with WITHOUT_SPEEDYCGI=yes"
	@${ECHO} ""
.endif
.if defined(WITH_PAM)
	@${ECHO} "PAM support will be added."
.endif
.if defined(WITH_ZLIB)
	@${ECHO} "Zlib support will be added."
.endif
.if defined(WITH_QUOTA)
	@${ECHO} "Quota support will be added."
.endif
.if defined(WITH_ISPELL)
	@${ECHO} "ISpell support will be added."
.endif
.if defined(WITH_ANTIWORD)
	@${ECHO} "Antiword support will be added."
.endif
.if defined(WITHOUT_SPEEDYCGI)
	@${ECHO} "SpeedyCGI support will NOT be added."
.endif
.if defined(WITH_IMAGEMAGICK)
	@${ECHO} "ImageMagick support will be added."
.endif
.if !defined(_CUSTOMIZED)
	@${ECHO} ""
	@${ECHO} "Type \"make WITH_PAM=yes\" if you want PAM support."
	@${ECHO} "Type \"make WITH_ZLIB=yes\" if you want Zlib support."
	@${ECHO} "Type \"make WITH_QUOTA=yes\" if you want Quota support."
	@${ECHO} "Type \"make WITH_ISPELL=yes\" if you want ISpell support."
	@${ECHO} "Type \"make WITH_ANTIWORD=yes\" if you want Antiword support."
	@${ECHO} "Type \"make WITHOUT_SPEEDYCGI=yes\" if you DONT want SpeedyCGI support."
	@${ECHO} "Type \"make WITH_IMAGEMAGICK=yes\" if you want ImageMagick support."
	@${ECHO} "You can use them in combinations."
	@${ECHO} ""
.endif

pre-patch:
	@${PERL} -pi.bak -e 's,${LOCALBASE}/bin/speedy_suid,${LOCALBASE}/bin/speedy_suidperl,g' ${PATCH_WRKSRC}/uty/*.diff

post-patch:
	@${MV} ${PATCH_WRKSRC}/etc/openwebmail.conf ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/cgi-bin/openwebmail,${OWCGIDIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
	@${PERL} -pi.bak -e 's,${LOCALBASE}/www/data/openwebmail,${OWDATADIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf-dist
.if !defined(WITHOUT_SPEEDYCGI)
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
	@${ECHO} "www/cgi-bin/openwebmail/etc/${f}.db" >> ${PLIST}
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
		| ${CPIO} -dpum -R ${BINOWN}:mail ${OWCGIDIR}
	@cd ${WRKSRC}/data/openwebmail && ${FIND} . \
		| ${CPIO} -dpum -R ${SHAREOWN}:${SHAREGRP} ${OWDATADIR}
.if !exists(${OWCGIDIR}/etc/openwebmail.conf)
	@${CP} ${OWCGIDIR}/etc/openwebmail.conf-dist ${OWCGIDIR}/etc/openwebmail.conf
.endif
	@${PERL} ${OWCGIDIR}/uty/dbmtest.pl | ${GREP} "^dbm" > ${OWCGIDIR}/etc/dbm.conf
.if defined(WITHOUT_SPEEDYCGI)
	@${PERL} ${OWCGIDIR}/uty/wrapsuid.pl ${OWCGIDIR}
.endif
	@${OWCGIDIR}/openwebmail-tool.pl --init --no

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
