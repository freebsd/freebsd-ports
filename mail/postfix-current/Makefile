# New ports collection makefile for:	postfix
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	postfix
PORTVERSION=	20001030
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.merit.edu/postfix/experimental/ \
		ftp://ftp.tux.org/pub/net/postfix/experimental/ \
		ftp://ftp.utoronto.ca/mirror/packages/postfix/experimental/ \
		ftp://ftp.samurai.com/pub/postfix/experimental/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/postfix/experimental/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/postfix/experimental/ \
		ftp://ftp.mira.net/pub/unix/mail/postfix/experimental/ \
		ftp://coda.nctu.edu.tw/network/mail/postfix/experimental/
DISTNAME=	snapshot-${PORTVERSION}

MAINTAINER=	dwcjr@inethouston.net

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
	sample-filter.cf sample-local.cf sample-misc.cf \
	sample-rate.cf sample-regexp.cf sample-relocated.cf \
	sample-resource.cf sample-rewrite.cf sample-smtp.cf \
	sample-smtpd.cf sample-transport.cf sample-virtual.cf

BIN1=	bounce cleanup error flush lmtp local master nqmgr pickup \
	pipe qmgr showq smtp smtpd spawn trivial-rewrite

BIN2=	postalias postcat postconf postdrop postfix \
	postkick postlog postmap postsuper sendmail

.if defined(WITH_TEST)
BIN3=   smtp-sink smtp-source
PLIST_SUB+=		WITH_TEST=""
.else
PLIST_SUB+=		WITH_TEST="@comment "
.endif

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

.if defined(CC)
MAKEFILEFLAGS+=	CC="${CC}"
.endif

MAKEFILEFLAGS+=	OPT="${CFLAGS}"

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=		${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql322-client
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/mysql/libmysqlclient.a -lm
.endif

.if defined(WITH_LDAP)
CONF2+=			sample-ldap.cf
BUILD_DEPENDS+=		${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libldap.a ${PREFIX}/lib/liblber.a
PLIST_SUB+=		WITH_LDAP=""
.else
PLIST_SUB+=		WITH_LDAP="@comment "
.endif

.if defined(WITH_PCRE)
CONF1+=			pcre_table
CONF2+=			sample-pcre.cf
MAN5+=			pcre_table.5
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libpcre.a
PLIST_SUB+=		WITH_PCRE=""
.else
PLIST_SUB+=		WITH_PCRE="@comment "
.endif

.if defined(WITH_SASL)
CONF2+=			sample-auth.cf
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsasl.a:${PORTSDIR}/security/cyrus-sasl
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libsasl.a -lpam -lcrypt
.if exists(/usr/lib/libkrb.a)
POSTFIX_AUXLIBS+=	-lkrb -ldes -lcom_err
.endif
PLIST_SUB+=		WITH_SASL=""
.else
PLIST_SUB+=		WITH_SASL="@comment "
.endif

post-patch:
	(cd ${WRKSRC} && make -f Makefile.init makefiles ${MAKEFILEFLAGS} \
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

.if defined(WITH_TEST)
.for file in ${BIN3}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/src/smtpstone/${file} \
		${PREFIX}/sbin
.endfor
.endif

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

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO_MSG} "===>  Activating postfix in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	${ECHO} "#" > /etc/mail/mailer.conf
	${ECHO} -n "# Execute the Postfix sendmail program" >> /etc/mail/mailer.conf
	${ECHO} ", named ${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "#" >> /etc/mail/mailer.conf
	${ECHO} "sendmail	${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "send-mail      ${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "mailq          ${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
	${ECHO} "newaliases     ${PREFIX}/sbin/sendmail" >> /etc/mail/mailer.conf
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
