# New ports collection makefile for:	openwebmail
# Date created:				24 April 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	openwebmail
PORTVERSION=	2.00
CATEGORIES=	mail
MASTER_SITES=	http://openwebmail.org/openwebmail/download/ \
		http://turtle.ee.ncku.edu.tw/openwebmail/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A webmail system designed to manage very big mail folder files in a memory efficient way

RUN_DEPENDS=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR=	${PREFIX}/www/cgi-bin/openwebmail
OWDATADIR=	${PREFIX}/www/data/openwebmail
PATCH_WRKSRC=	${WRKSRC}/cgi-bin/openwebmail
PATCH_STRIP=	-p1

.if defined(WITH_SPEEDYCGI)
BUILD_DEPENDS+=	${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI
RUN_DEPENDS+=	${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI
EXTRA_PATCHES=	${PATCH_WRKSRC}/uty/suidperl2speedy.diff
.endif

.if defined(WITH_PAM)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

pre-fetch:
.if defined(WITH_PAM)
	@${ECHO} "PAM support will be added."
.endif
.if defined(WITH_ISPELL)
	@${ECHO} "ISpell support will be added."
.endif
.if defined(WITH_SPEEDYCGI)
	@${ECHO} "SpeedyCGI support will be added."
.endif
.if defined(WITH_IMAGEMAGICK)
	@${ECHO} "ImageMagick support will be added."
.endif
.if !defined(WITH_PAM) && !defined(WITH_ISPELL) && !defined(WITH_IMAGEMAGICK) && !defined(WITH_SPEEDYCGI)
	@${ECHO} ""
	@${ECHO} "Type \"make WITH_PAM=yes\" if you want PAM support."
	@${ECHO} "Type \"make WITH_ISPELL=yes\" if you want ISpell support."
	@${ECHO} "Type \"make WITH_SPEEDYCGI=yes\" if you want SpeedyCGI support."
	@${ECHO} "Type \"make WITH_IMAGEMAGICK=yes\" if you want ImageMagick support."
	@${ECHO} "You can use them in combinations."
	@${ECHO} ""
.endif

post-patch:
	@${PERL} -pi.bak -e 's,/usr/local/www/cgi-bin/openwebmail,${OWCGIDIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf
	@${PERL} -pi.bak -e 's,/usr/local/www/data/openwebmail,${OWDATADIR},g' ${PATCH_WRKSRC}/etc/openwebmail.conf
.if defined(WITH_SPEEDYCGI)
	@${ECHO} "savedsuid_support	no" >> ${PATCH_WRKSRC}/etc/openwebmail.conf
.else
	@${PERL} -pi.bak -e 's,/usr/bin/suidperl,${PERL},g' ${PATCH_WRKSRC}/openwebmail*pl
.endif

do-install:
	@${CP} -R ${WRKSRC}/cgi-bin/openwebmail/ ${OWCGIDIR}
	@${CP} -R ${WRKSRC}/data/openwebmail/ ${OWDATADIR}
	@${CHOWN} -R root:mail ${OWCGIDIR}
	@${CHMOD} 0770 ${OWCGIDIR}/etc/sessions ${OWCGIDIR}/etc/users
	@${CHMOD} 4755 ${OWCGIDIR}/openwebmail*pl
	@${PERL} ${OWCGIDIR}/uty/wrapsuid.pl ${OWCGIDIR}
	@${OWCGIDIR}/openwebmail-tool.pl --init --no
	@${FIND} ${OWCGIDIR} \( -name "*.bak" -or -name "*.orig" \) -delete

.include <bsd.port.mk>
