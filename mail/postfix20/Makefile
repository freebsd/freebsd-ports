# New ports collection makefile for:	postfix
# Version required:	postfix 19990317-pl03
# Date created:		18 Mar 1999
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1999/03/29 20:15:08 torstenb Exp $
#

DISTNAME=	postfix-19990317-pl03
PKGNAME=	postfix-alpha-19990317.03
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.merit.edu/postfix/ \
		ftp://ftp.snoopy.net/pub/mirrors/postfix/ \
		ftp://ftp.reverse.net/pub/postfix/ \
		ftp://postfix.eu.org/pub/postfix/ \
		ftp://ftp.sunet.se/pub/unix/mail/postfix/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/postfix/ \
		ftp://ftp.postfix.oaktree.co.uk/pub/postfix/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=	default "OPT=${CFLAGS}"

SCRIPTS_ENV+=	MAN1="${MAN1}" MAN5="${MAN5}" MAN8="${MAN8}"

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postsuper.1 \
	sendmail.1
MAN5=	access.5 aliases.5 canonical.5 relocated.5 transport.5 virtual.5
MAN8=	bounce.8 cleanup.8 defer.8 local.8 master.8 pickup.8 pipe.8 qmgr.8 \
	showq.8 smtp.8 smtpd.8 trivial-rewrite.8

SHAREMODE=	0644

do-install:
	@${MKDIR} -m 755 ${PREFIX}/etc/postfix
	@chown root:wheel ${PREFIX}/etc/postfix
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
	@mkdir -p -m 0755 ${PREFIX}/libexec/postfix
	@for f in bounce cleanup fsstone local master pickup pipe \
		qmgr showq smtp smtp-sink smtp-source smtpd \
		trivial-rewrite ; do \
		${INSTALL} -C -o root -g wheel -m 0755 ${WRKSRC}/bin/$$f \
			${PREFIX}/libexec/postfix/$$f ;\
	done
	@for f in sendmail postalias postcat postconf postfix \
		postkick postlock postlog postmap postsuper ; do \
		${INSTALL} -C -o root -g wheel -m 0755 ${WRKSRC}/bin/$$f \
			${PREFIX}/sbin/$$f ;\
	done
	@${INSTALL} -C -o root -g wheel -m 0555 ${WRKSRC}/bin/postdrop \
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
	@mkdir -p -m 0755 /var/spool/postfix
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
		chmod 0 /usr/sbin/sendmail.OFF; \
	fi
	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/sbin/sendmail; \
	fi
	@${ECHO_MSG} "===> Replacing mailq"
	@if [ -e /usr/bin/mailq ]; then \
		${MV} -f /usr/bin/mailq /usr/bin/mailq.OFF; \
		chmod 0 /usr/bin/mailq.OFF; \
	fi
	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/bin/mailq; \
	fi
	@${ECHO_MSG} "===> Replacing newaliases"
	@if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.OFF; \
		chmod 0 /usr/bin/newaliases.OFF; \
	fi
	@if [ -e ${PREFIX}/sbin/sendmail ]; then \
		${LN} -s ${PREFIX}/sbin/sendmail /usr/bin/newaliases; \
	fi

.include <bsd.port.mk>
