# New ports collection makefile for:	MailScanner
# Date created:				17 March 2003
# Whom:					Jan-Peter Koopmann <j.koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	mailscanner
PORTVERSION=	4.25.14
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.sng.ecs.soton.ac.uk/mailscanner/files/4/tar/
DISTNAME=	MailScanner-4.25-14

MAINTAINER=	j.koopmann@seceidos.de
COMMENT=	Powerful virus/spam scanning framework for Sendmail/Exim

BUILD_DEPENDS=	\
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
	${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
	${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net/p5-Net-CIDR

RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

CONFLICTS=	MailScanner-devel-*

USE_PERL5=	yes

DATADIR=	${PREFIX}/share/MailScanner
DOCSDIR=	${PREFIX}/share/doc/MailScanner
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN8=		MailScanner.8
MAN5=		MailScanner.conf.5
MLINKS=		MailScanner.8 mailscanner.8 \
		MailScanner.conf.5 mailscanner.conf.5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

DOC_FILES=	INSTALL INSTALL.FreeBSD INSTALL.OpenBSD README
ETC_FILES=	MailScanner.conf filename.rules.conf \
		filetype.rules.conf spam.assassin.prefs.conf \
		spam.lists.conf virus.scanners.conf

do-build:
	${PERL} -pi -e \
		's,/opt/MailScanner/lib,'${PREFIX}'/lib/MailScanner,g; \
		s,/opt/MailScanner/etc,'${PREFIX}'/etc/MailScanner,g;' \
		${WRKSRC}/bin/MailScanner
	${PERL} -pi -e \
		's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g; \
		s,/usr/lib/sendmail,/usr/sbin/sendmail,g; \
		s,/opt/MailScanner/bin,'${PREFIX}'bin,g; \
		s,/opt/MailScanner/etc/reports,'${DATADIR}'/reports,g; \
		s,/opt/MailScanner/etc,'${PREFIX}'/etc/MailScanner,g;' \
		${WRKSRC}/etc/MailScanner.conf
	${PERL} -pi -e \
		's,/opt/MailScanner/lib,'${PREFIX}'/libexec/MailScanner,g; \
		s,/bin/false,/usr/bin/false,;' ${WRKSRC}/etc/virus.scanners.conf
	${PERL} -pi -e \
		's,/bin/bash,'${LOCALBASE}'/bin/bash,g; \
		s,/opt/MailScanner/etc,'${PREFIX}'/etc/MailScanner,g;' \
		${WRKSRC}/bin/update_virus_scanners
	${PERL} -pi -e \
		's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g; \
		s,/usr/lib/sendmail,/usr/sbin/sendmail,g; \
		s,/opt/MailScanner/bin,'${PREFIX}'/bin,g; \
		s,/opt/MailScanner/etc/reports,'${DATADIR}'/reports,g; \
		s,/opt/MailScanner/etc,'${PREFIX}'/etc/MailScanner,g;' \
		${WRKSRC}/lib/MailScanner/ConfigDefs.pl
	${PERL} -pi \
		-e 's,/bin/sed,/usr/bin/sed,g;' ${WRKSRC}/lib/MailScanner/SystemDefs.pm

do-install:
	#
	# Step 1: Install binaries
	#
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tnef.linux ${PREFIX}/bin/tnef
	#
	# Step 2: Install libexec files
	#
	${MKDIR} ${PREFIX}/libexec/MailScanner
	${CHMOD} -R ${BINMODE} ${PREFIX}/libexec/MailScanner
	${INSTALL_SCRIPT} ${WRKSRC}/bin/MailScanner ${PREFIX}/libexec/MailScanner
	cd ${WRKSRC}/lib && ${FIND} * -name "*-wrapper" -exec ${INSTALL_SCRIPT} \
		'{}' ${PREFIX}'/libexec/MailScanner/{}'.sample \;
	cd ${WRKSRC}/lib && ${FIND} * -name "*-autoupdate" -exec \
		${INSTALL_SCRIPT} '{}' ${PREFIX}'/libexec/MailScanner/{}'.sample \;
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_virus_scanners \
		${PREFIX}/libexec/MailScanner/update_virus_scanners
	#
	# Step 3: Install etc files
	#
	${MKDIR} ${PREFIX}/etc/MailScanner
	${CHMOD} ${BINMODE} ${PREFIX}/etc/MailScanner
.for FILE in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${PREFIX}/etc/MailScanner/${FILE}.sample
.endfor
	${MKDIR} ${PREFIX}/etc/MailScanner/rules
	cd ${WRKSRC}/etc/rules && \
		${INSTALL_DATA} EXAMPLES README ${PREFIX}/etc/MailScanner/rules
	${INSTALL_DATA} ${WRKSRC}/etc/rules/spam.whitelist.rules \
		${PREFIX}/etc/MailScanner/rules/spam.whitelist.rules.sample

	#
	# Step 4: Install files in share
	#
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/etc && ${FIND} reports -type d -exec \
		mkdir ${DATADIR}'/{}' \;
	cd ${WRKSRC}/etc && ${FIND} reports -type f ! -name "*.orig" -exec \
		${INSTALL_DATA} '{}' ${DATADIR}'/{}'.sample \;
	${CHMOD} -R ${BINMODE} ${DATADIR}/reports
	#
	# Step 5: Install lib
	#
	${MKDIR} ${PREFIX}/lib/MailScanner/MailScanner
	${INSTALL_SCRIPT} ${WRKSRC}/lib/MailScanner.pm \
		${PREFIX}/lib/MailScanner/MailScanner.pm
	cd ${WRKSRC}/lib/MailScanner && ${FIND} * -type f ! -name "*.orig" -exec \
		${INSTALL_SCRIPT} '{}' ${PREFIX}'/lib/MailScanner/MailScanner/{}' \;
	#
	# Step 6: Install Start/Stop scripts
	#
	${INSTALL_SCRIPT} ${FILESDIR}/mailscanner.sh \
		${PREFIX}/etc/rc.d/mailscanner.sh.sample
	${INSTALL_SCRIPT} ${FILESDIR}/mta.sh ${PREFIX}/etc/rc.d/mta.sh.sample
	#
	# Step 7: Docs & Manpages
	#
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD.port ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${FIND} * -type d -exec mkdir ${DOCSDIR}'/{}' \; && \
		${FIND} * -type f ! -name "*.orig" -exec \
			${INSTALL_DATA} '{}' ${DOCSDIR}'/{}' \;
	cd ${WRKSRC}/docs/man && \
		${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5 && \
		${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8
.endif
.if exists(${PREFIX}/etc/MailScanner/MailScanner.conf)
	# Upgrading MailScanner.conf file... Please wait
	@${WRKSRC}/bin/upgrade_MailScanner_conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf.sample > \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} \
		2> /dev/null
	# Diff the files. If the files do not differ, delete the new file
	@if diff -b -B -q ${PREFIX}/etc/MailScanner/MailScanner.conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	   then ${ECHO} "No changes in MailScanner.conf options found" ; \
		${RM} ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	else \
	   ${ECHO} "Changes in MailScanner.conf found. Please look at \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION}" ; \
	fi
.endif
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

renew-wrapper: install
	# Renew virus wrapper scripts
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*-wrapper ${PREFIX}/libexec/MailScanner

renew-autoupdate: install
	# Renew autoupdate scripts
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*-autoupdate ${PREFIX}/libexec/MailScanner

renew-reports: install
	# Renew reports
	cd ${WRKSRC}/etc/reports/en && ${FIND} * -type f ! -name "*.orig" \
		-exec ${INSTALL_DATA} '{}' ${DATADIR}'/reports/en/{}'  \;

initial-config: renew-wrapper renew-autoupdate renew-reports
	cd ${WRKSRC}/etc && ${INSTALL_DATA} ${ETC_FILES} \
		${PREFIX}/etc/MailScanner
	${INSTALL_DATA} ${WRKSRC}/etc/rules/spam.whitelist.rules \
		${PREFIX}/etc/MailScanner/rules/spam.whitelist.rules

.include <bsd.port.post.mk>
