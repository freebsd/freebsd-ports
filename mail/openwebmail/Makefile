# New ports collection makefile for:	openwebmail
# Date created:				24 April 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	openwebmail
PORTVERSION=	1.81
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://openwebmail.org/openwebmail/download/ \
		http://turtle.ee.ncku.edu.tw/openwebmail/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR=	${PREFIX}/www/cgi-bin/openwebmail
USE_REINPLACE=	yes

do-install:
.for dir in cgi-bin data
	@${MKDIR} ${PREFIX}/www/${dir}
	@${CP} -R ${WRKSRC}/${dir}/openwebmail ${PREFIX}/www/${dir}/
	@${CHOWN} -R root:mail ${PREFIX}/www/${dir}/openwebmail
.endfor
.for dir in sessions users
	@${CHMOD} 0770 ${OWCGIDIR}/etc/${dir}
.endfor
.for file in openwebmail-abook.pl openwebmail-advsearch.pl openwebmail-cal.pl \
	openwebmail-folder.pl openwebmail-main.pl openwebmail-prefs.pl \
	openwebmail-read.pl openwebmail-send.pl openwebmail-spell.pl \
	openwebmail-tool.pl openwebmail-viewatt.pl openwebmail.pl
	@${REINPLACE_CMD} -e 's,suidperl,perl,g' ${OWCGIDIR}/${file}
	@${CHMOD} 4555 ${OWCGIDIR}/${file}
.endfor
	@${PERL5} ${WRKSRC}/cgi-bin/openwebmail/uty/wrapsuid.pl ${OWCGIDIR}
	@${OWCGIDIR}/openwebmail-tool.pl --init -y
	@${RM} ${OWCGIDIR}/*orig ${OWCGIDIR}/*bak

.include <bsd.port.mk>
