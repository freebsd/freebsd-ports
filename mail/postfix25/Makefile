# New ports collection makefile for:	postfix
# Version required:	19991231
# Date created:		18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	postfix-19991231-pl06
PKGNAME=	postfix-19991231.06
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.merit.edu/postfix/official/ \
		ftp://ftp.snoopy.net/pub/mirrors/postfix/official/ \
		ftp://ftp.reverse.net/pub/postfix/official/ \
		ftp://postfix.eu.org/pub/postfix/official/ \
		ftp://ftp.sunet.se/pub/unix/mail/postfix/official/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/postfix/official/ \
		ftp://ftp.postfix.oaktree.co.uk/pub/postfix/official/

MAINTAINER=	torstenb@FreeBSD.org

# WARNING: this is based on a patch submitted by a user and has not been
# tested. Use it at your own risk !
.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
BUILD_DEPENDS+=		${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql322-client
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/mysql/libmysqlclient.a -lm
.endif

# WARNING: this is based on a patch submitted by a user and has not been
# tested. Use it at your own risk !
.if defined(USE_LDAP) && ${USE_LDAP} == YES
BUILD_DEPENDS+=		${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libldap.a ${PREFIX}/lib/liblber.a
.endif

ALL_TARGET=	CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}"

SCRIPTS_ENV+=	MAN1="${MAN1}" MAN5="${MAN5}" MAN8="${MAN8}"
MAKE_ENV+=	"OPT=${CFLAGS}"

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postsuper.1 \
	sendmail.1
MAN5=	access.5 aliases.5 canonical.5 relocated.5 transport.5 virtual.5
MAN8=	bounce.8 cleanup.8 defer.8 local.8 master.8 pickup.8 pipe.8 qmgr.8 \
	showq.8 smtp.8 smtpd.8 trivial-rewrite.8 error.8

SHAREMODE=	0444
PDOC=		${PREFIX}/share/doc/postfix

do-install:
	@${MKDIR} -m 755 ${PREFIX}/etc/postfix
	@${CHOWN} root:wheel ${PREFIX}/etc/postfix
	@${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/LICENSE \
		${PREFIX}/etc/postfix/LICENSE
	@for f in access main.cf master.cf ; do \
		${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/$$f \
		${PREFIX}/etc/postfix/sample-$$f ; \
	done
	@for f in sample-aliases.cf sample-canonical.cf sample-debug.cf \
		sample-ldap.cf sample-local.cf sample-misc.cf sample-pcre.cf \
		sample-rate.cf sample-relocated.cf sample-resource.cf \
		sample-rewrite.cf sample-smtp.cf sample-smtpd.cf \
		sample-transport.cf sample-virtual.cf ; do \
		${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/$$f \
		${PREFIX}/etc/postfix/$$f ;\
	done
	@${INSTALL} -C -o root -g wheel -m 755 ${WRKSRC}/conf/postfix-script-sgid \
		${PREFIX}/etc/postfix/postfix-script
	@${MKDIR} -m 0755 ${PREFIX}/libexec/postfix
	@for f in bounce cleanup error local master pickup pipe qmgr \
		 showq smtp smtpd trivial-rewrite ; do \
		${INSTALL} -C -o root -g wheel -m 0755 -s \
			${WRKSRC}/libexec/$$f ${PREFIX}/libexec/postfix/$$f ;\
	done
	@for f in postalias postcat postconf postfix postkick postlock postlog\
		postmap postsuper sendmail smtp-sink smtp-source ; do \
		${INSTALL} -C -o root -g wheel -m 0755 -s ${WRKSRC}/bin/$$f \
			${PREFIX}/sbin/$$f ;\
	done
	@${INSTALL} -C -o root -g maildrop -m 2755 -s ${WRKSRC}/bin/postdrop \
		${PREFIX}/sbin/postdrop
	@for f in ${MAN1} ; do \
		${INSTALL} -C -o root -g wheel -m 0755 ${WRKSRC}/man/man1/$$f \
			${PREFIX}/man/man1/$$f ;\
	done
	@for f in ${MAN5} ; do \
		${INSTALL} -C -o root -g wheel -m 0755 ${WRKSRC}/man/man5/$$f \
			${PREFIX}/man/man5/$$f ;\
	done
	@for f in ${MAN8} ; do \
		${INSTALL} -C -o root -g wheel -m 0755 ${WRKSRC}/man/man8/$$f \
			${PREFIX}/man/man8/$$f ;\
	done
	@${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${PDOC}
	@cd ${WRKSRC} && ${INSTALL_DATA} \
		html/*.html html/*.gif ${PDOC} && \
		${ECHO_MSG} "Installed HTML documentation in ${PDOC}"
	@${MKDIR} -m 0755 /var/spool/postfix
	@${ECHO_MSG} "--------------------------------------------------"
	@${ECHO_MSG} "- To replace your existing sendmail with postfix -"
	@${ECHO_MSG} "- type \"make replace\"                          -"
	@${ECHO_MSG} "--------------------------------------------------"

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO_MSG} "===> Activating postfix in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	${ECHO} 'sendmail	${PREFIX}/sbin/sendmail' > /etc/mail/mailer.conf
	${ECHO} 'send-mail	${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
	${ECHO} 'mailq		${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
	${ECHO} 'newaliases	${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
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
