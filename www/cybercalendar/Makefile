# New ports collection makefile for:	cybercalendar
# Date created:		17 June 2002
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$

PORTNAME=	cybercalendar
PORTVERSION=	1.8.2
CATEGORIES=	www
MASTER_SITES=	http://www.cyberweavers.com/download/ \
		http://6net.iif.hu/~mohacsi/downloads/
DISTNAME=	CyberCalendar_${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	CyberCalendar is a web based calendar program written in perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite

WRKSRC=		${WRKDIR}/CyberCalendar

USE_PERL5=	yes
NO_BUILD=	yes
NO_PACKAGE=	"needs customization and postconfiguration"

DOC_FILES=	README INSTALL INSTALL.NOSITEPERL TODO CHANGES COPYING
SCRIPT_FILES=	calendar/index.pl calendar/optionform.pl calendar/pda.pl \
	calendar/printable.pl calendar/submit.pl calendar/vcal.pl \
	calendar/admin/admin.pl calendar/admin/index.pl calendar/admin/setup.pl

do-install:
	@if [ ! -d ${PREFIX}/cybercalendar ]; then \
		${MKDIR} ${PREFIX}/cybercalendar; fi
	@${CP} -R ${WRKSRC}/calendar ${PREFIX}/cybercalendar
	@${CP} -R ${WRKSRC}/CyberCalendar ${PREFIX}/cybercalendar
.for file in ${SCRIPT_FILES}
	@${CHMOD} 755 ${PREFIX}/cybercalendar/${file}
.endfor
	${LN} -s ${PREFIX}/cybercalendar/CyberCalendar \
		${PREFIX}/cybercalendar/calendar
	${LN} -s ${PREFIX}/cybercalendar/CyberCalendar \
		${PREFIX}/cybercalendar/calendar/admin
	@${CP} -R ${WRKSRC}/setup ${PREFIX}/cybercalendar
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.changes \
		${PREFIX}/cybercalendar/setup

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
