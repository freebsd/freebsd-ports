# New ports collection makefile for:	openwebmail
# Date created:				24 April 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	openwebmail
PORTVERSION=	1.62
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://turtle.ee.ncku.edu.tw/openwebmail/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@leeym.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
OWCGIDIR=	${PREFIX}/www/cgi-bin/openwebmail
SUIDPERL=	/usr/bin/suidperl

do-install:
.for dir in cgi-bin data
	@${CP} -R ${WRKSRC}/${dir}/openwebmail ${PREFIX}/www/${dir}/
	@${CHOWN} -R root:mail ${PREFIX}/www/${dir}/openwebmail
.endfor
.for file in auth_pop3.pl openwebmail-main.pl openwebmail-prefs.pl openwebmail-read.pl openwebmail-send.pl openwebmail-viewatt.pl openwebmail.pl
	@${CHMOD} 4555 ${SUIDPERL}
	@${PERL5} -pi -e 's,/usr/bin/perl,${SUIDPERL},g' ${OWCGIDIR}/${file}
	@${CHMOD} 4555 ${OWCGIDIR}/${file}
.endfor
.for dir in sessions users
	@${CHMOD} 0770 ${OWCGIDIR}/etc/${dir}
.endfor
	@${CHMOD} 0755 ${OWCGIDIR}/etc ${OWCGIDIR}/vacation.pl

.include <bsd.port.mk>
