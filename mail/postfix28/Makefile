# New ports collection makefile for:	postfix
# Version required:	19990601
# Date created:		18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	postfix-19990906-pl02
PKGNAME=	postfix-19990906.02
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.merit.edu/postfix/official/ \
		ftp://ftp.snoopy.net/pub/mirrors/postfix/official/ \
		ftp://ftp.reverse.net/pub/postfix/official/ \
		ftp://postfix.eu.org/pub/postfix/official/ \
		ftp://ftp.sunet.se/pub/unix/mail/postfix/official/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/postfix/official/ \
		ftp://ftp.postfix.oaktree.co.uk/pub/postfix/official/

MAINTAINER=	torstenb@FreeBSD.org

ALL_TARGET=	default

SCRIPTS_ENV+=	MAN1="${MAN1}" MAN5="${MAN5}" MAN8="${MAN8}"
MAKE_ENV+=	"OPT=${CFLAGS}"

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postsuper.1 \
	sendmail.1
MAN5=	access.5 aliases.5 canonical.5 relocated.5 transport.5 virtual.5
MAN8=	bounce.8 cleanup.8 defer.8 local.8 master.8 pickup.8 pipe.8 qmgr.8 \
	showq.8 smtp.8 smtpd.8 trivial-rewrite.8 error.8

SHAREMODE=	0644

do-install:
	@${MKDIR} -m 755 ${PREFIX}/etc/postfix
	@${CHOWN} root:wheel ${PREFIX}/etc/postfix
	@${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/LICENSE \
		${PREFIX}/etc/postfix/LICENSE
	@for f in access main.cf master.cf ; do \
		${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/$$f \
		${PREFIX}/etc/postfix/sample-$$f ; \
	done
	@exit
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
	@for f in postalias postcat postconf postdrop postfix postkick \
		postlock postlog postmap postsuper sendmail smtp-sink \
		smtp-source ; do \
		${INSTALL} -C -o root -g wheel -m 0755 -s ${WRKSRC}/bin/$$f \
			${PREFIX}/sbin/$$f ;\
	done
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
	@${MKDIR} -m 0755 /var/spool/postfix
	@if [ ! -e ${PREFIX}/etc/postfix/main.cf ]; then \
		${CP} -p ${PREFIX}/etc/postfix/sample-main.cf \
			${PREFIX}/etc/postfix/main.cf; \
	fi
	@if [ ! -e ${PREFIX}/etc/postfix/master.cf ]; then \
		${CP} -p ${PREFIX}/etc/postfix/sample-master.cf \
			${PREFIX}/etc/postfix/master.cf; \
	fi
	@${ECHO_MSG} "--------------------------------------------------"
	@${ECHO_MSG} "- To replace your existing sendmail with postfix -"
	@${ECHO_MSG} "- type \"make replace\"                          -"
	@${ECHO_MSG} "--------------------------------------------------"

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

replace:
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

.include <bsd.port.mk>
