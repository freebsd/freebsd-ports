# New ports collection makefile for:	postfix
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	postfix
PORTVERSION=	20010228.1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/ \
		ftp://ftp.aet.tu-cottbus.de/pub/postfix_tls/%SUBDIR%/ \
		ftp://ftp.tux.org/pub/net/postfix/official/ \
		ftp://ftp.utoronto.ca/mirror/packages/postfix/official/ \
		ftp://ftp.samurai.com/pub/postfix/official/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/postfix/official/&,}
MASTER_SITE_SUBDIR= . old related/postfix
DISTNAME=	postfix-20010228-pl01
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	blaz@amis.net

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postsuper.1 \
	sendmail.1

MAN5=	access.5 aliases.5 canonical.5 regexp_table.5 relocated.5 \
	transport.5 virtual.5

MAN8=	bounce.8 cleanup.8 defer.8 error.8 flush.8 lmtp.8 local.8 \
	master.8 pickup.8 pipe.8 qmgr.8 showq.8 smtp.8 smtpd.8 \
	spawn.8 trivial-rewrite.8

CONF1=	access aliases canonical main.cf master.cf \
	regexp_table relocated transport virtual

CONF2=	sample-aliases.cf sample-canonical.cf sample-debug.cf \
	sample-filter.cf sample-flush.cf sample-local.cf sample-misc.cf \
	sample-rate.cf sample-regexp.cf sample-relocated.cf \
	sample-resource.cf sample-rewrite.cf sample-smtp.cf \
	sample-smtpd.cf sample-transport.cf sample-virtual.cf

BIN1=	bounce cleanup error flush lmtp local master pickup \
	pipe qmgr showq smtp smtpd spawn trivial-rewrite

BIN2=	postalias postcat postconf postdrop postfix \
	postkick postlock postlog postmap postsuper sendmail

.if defined(NOPORTDOCS)
PLIST_SUB+=	SUB_DOCS="@comment "
.else
PLIST_SUB+=	SUB_DOCS=""
DOCDIR=		${PREFIX}/share/doc/postfix
.endif

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

.if defined(CC)
MAKEFILEFLAGS+=	CC="${CC}"
.endif

MAKEFILEFLAGS+=	OPT="${CFLAGS}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		MAN1="${MAN1}" MAN5="${MAN5}" MAN8="${MAN8}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.postfix

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-patch:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.init makefiles ${MAKEFILEFLAGS} \
	CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}" && \
	${ECHO} "all: default" >> Makefile)

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 \
		${PREFIX}/etc/postfix \
		${PREFIX}/libexec/postfix \
		/var/spool/postfix
	@${INSTALL_DATA} ${WRKSRC}/conf/LICENSE ${PREFIX}/etc/postfix

.for file in ${CONF1}
	@${INSTALL_DATA} \
		${WRKSRC}/conf/${file} \
		${PREFIX}/etc/postfix/sample-${file}
.endfor

.for file in ${CONF2}
	@${INSTALL_DATA} \
		${WRKSRC}/conf/${file} \
		${PREFIX}/etc/postfix
.endfor

	@${INSTALL_SCRIPT} \
		${WRKSRC}/conf/postfix-script-sgid \
		${PREFIX}/etc/postfix/postfix-script

.for file in ${BIN1}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/libexec/${file} \
		${PREFIX}/libexec/postfix
.endfor

.for file in ${BIN2}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/src/${file}/${file} \
		${PREFIX}/sbin
.endfor

.for file in ${BIN3}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/src/smtpstone/${file} \
		${PREFIX}/sbin
.endfor

.for file in ${MAN1}
	@${INSTALL_MAN} \
		${WRKSRC}/man/man1/${file} \
		${PREFIX}/man/man1
.endfor

.for file in ${MAN5}
	@${INSTALL_MAN} \
		${WRKSRC}/man/man5/${file} \
		${PREFIX}/man/man5
.endfor

.for file in ${MAN8}
	@${INSTALL_MAN} \
		${WRKSRC}/man/man8/${file} \
		${PREFIX}/man/man8
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCDIR}
	@cd ${WRKSRC}/html && ${INSTALL_DATA} *.html *.gif ${DOCDIR} && \
		${ECHO_MSG} "Installed HTML documentation in ${DOCDIR}"
.endif

	@${ECHO_MSG} '--------------------------------------------------'
	@${ECHO_MSG} '- To replace your existing sendmail with postfix -'
	@${ECHO_MSG} '- type "make replace"                            -'
	@${ECHO_MSG} '--------------------------------------------------'

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO_MSG} "===> Activating postfix in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	${ECHO} "#" > /etc/mail/mailer.conf
	${ECHO} -n "# Execute the Postfix sendmail program" >> /etc/mail/mailer.conf
	${ECHO} ", named ${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "#" >> /etc/mail/mailer.conf
	${ECHO} "sendmail	${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "send-mail	${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "mailq		${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "newaliases	${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
.else
	@${ECHO_MSG} "===> Replacing sendmail"
	@if [ -e /usr/sbin/sendmail ]; then \
		${MV} -f /usr/sbin/sendmail /usr/sbin/sendmail.OFF; \
		${CHMOD} 0 /usr/sbin/sendmail.OFF; \
	fi

	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/sbin/sendmail; \
	fi

	@${ECHO_MSG} "===> Replacing mailq"
	@if [ -e /usr/bin/mailq ]; then \
		${MV} -f /usr/bin/mailq /usr/bin/mailq.OFF; \
		${CHMOD} 0 /usr/bin/mailq.OFF; \
	fi

	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/bin/mailq; \
	fi

	@${ECHO_MSG} "===> Replacing newaliases"
	@if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.OFF; \
		${CHMOD} 0 /usr/bin/newaliases.OFF; \
	fi

	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/bin/newaliases; \
	fi
.endif

.include <bsd.port.post.mk>
