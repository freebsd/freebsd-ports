# New ports collection makefile for:  	MailScanner
# Date created:                		17 March 2003
# Whom:                        		Jan-Peter Koopmann <j.koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	mailscanner
PORTVERSION=	4.22.5
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.sng.ecs.soton.ac.uk/mailscanner/files/4/tar/
DISTNAME=	MailScanner-4.22-5

MAINTAINER=	j.koopmann@seceidos.de
COMMENT=	A powerful virus/spam scanning framework for Sendmail and Exim

BUILD_DEPENDS=	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF

RUN_DEPENDS=	${BUILD_DEPENDS}
DATADIR=	${PREFIX}/share/MailScanner
DOCSDIR=	${PREFIX}/share/doc/MailScanner

MAN8=		MailScanner.8
MAN5=		MailScanner.conf.5
MLINKS=		MailScanner.8 mailscanner.8 MailScanner.conf.5 mailscanner.conf.5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+= ${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=   ${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

#    PATCH_DIST_STRIP=      -p1

USE_PERL5=	yes

pre-install:
	# Delete WRKSRC/.install_*
	${RM} -rf ${WRKSRC}/.install_*

do-install:
	( cd ${WRKSRC} ; ${MAKE} ${INSTALL_TARGET} BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" SHAREOWN="${SHAREOWN}" SHAREGRP="{SHAREGRP}" SHAREMODE="${SHAREMODE}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" INSTALL_DATA="${INSTALL_DATA}" PREFIX="${PREFIX}" WRKSPACE="${WRKSPACE}" OVERWRITE_FILENAMERULES="${OVERWRITE_FILENAMERULES}" OVERWRITE_REPORTS="${OVERWRITE_REPORTS}" )

post-install:
.for file in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${file} ${PREFIX}/man/man5
.endfor

.for file in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${file} ${PREFIX}/man/man8
.endfor

.if exists(${PREFIX}/etc/MailScanner/MailScanner.conf)
	# Upgrading MailScanner.conf file... Please wait
	@${WRKSRC}/bin/upgrade_MailScanner_conf ${PREFIX}/etc/MailScanner/MailScanner.conf ${PREFIX}/etc/MailScanner/MailScanner.conf.sample > ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} 2> /dev/null
	# Diff the files. If the files do not differ, delete the new file
	@if diff -b -B -q ${PREFIX}/etc/MailScanner/MailScanner.conf ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	   then ${ECHO} "No changes in MailScanner.conf options found" ; ${RM} ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	else \
	   ${ECHO} "Changes in MailScanner.conf found. Please look at ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION}" ; \
	fi

.endif

	@${SED} -e 's#PREFIX#${PREFIX}#' pkg-message

initial-config:
	( cd ${WRKSRC} ; ${MAKE} initial-config BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" SHAREOWN="${SHAREOWN}" SHAREGRP="{SHAREGRP}" SHAREMODE="${SHAREMODE}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" INSTALL_DATA="${INSTALL_DATA}" PREFIX="${PREFIX}" WRKSPACE="${WRKSPACE}" OVERWRITE_FILENAMERULES="${OVERWRITE_FILENAMERULES}" OVERWRITE_REPORTS="${OVERWRITE_REPORTS}" )

.include <bsd.port.post.mk>
