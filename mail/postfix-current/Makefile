# New ports collection makefile for:	postfix
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	postfix
PORTVERSION=	20000531
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.merit.edu/postfix/experimental/ \
		ftp://ftp.tux.org/pub/net/postfix/experimental/ \
		ftp://ftp.utoronto.ca/mirror/packages/postfix/experimental/ \
		ftp://ftp.samurai.com/pub/postfix/experimental/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/postfix/experimental/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/postfix/experimental/ \
		ftp://ftp.mira.net/pub/unix/mail/postfix/experimental/ \
		ftp://coda.nctu.edu.tw/network/mail/postfix/experimental/
DISTNAME=	snapshot-20000531

MAINTAINER=	missnglnk@sneakerz.org

.if !defined(DEBUG)
MAKEFILEFLAGS+= DEBUG=
.endif

.if defined(CC)
MAKEFILEFLAGS+= CC=$(CC)
.endif

.if defined(OPT)
MAKEFILEFLAGS+= OPT=$(OPT)
.endif

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=		${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql322-client
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/mysql/libmysqlclient.a -lm
.endif

.if defined(WITH_LDAP)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libldap.a ${PREFIX}/lib/liblber.a
.endif

.if defined(WITH_PCRE)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libpcre.a
.endif

.if defined(WITH_SASL)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsasl.a:${PORTSDIR}/security/cyrus-sasl
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	${LOCALBASE}/lib/libsasl.a
.endif

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postsuper.1 \
	sendmail.1

MAN5=	access.5 aliases.5 canonical.5 regexp_table.5 relocated.5 \
	transport.5 virtual.5

.ifdef(WITH_PCRE)
MAN5+=	pcre_table.5
.endif

MAN8=	bounce.8 cleanup.8 defer.8 error.8 lmtp.8 local.8 master.8 \
	pickup.8 pipe.8 qmgr.8 showq.8 smtp.8 smtpd.8 trivial-rewrite.8

post-patch:
	(cd ${WRKSRC} && make -f Makefile.init makefiles ${MAKEFILEFLAGS} \
	CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}" && \
	${ECHO} "all: default" >> Makefile)

pre-install:
	@${SH} @${PKGDIR}/INSTALL Postfix PRE-INSTALL

do-install:
	@${MKDIR} -m 755 ${PREFIX}/etc/postfix
	@${CHOWN} root:wheel ${PREFIX}/etc/postfix
	@${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/LICENSE \
		${PREFIX}/etc/postfix/LICENSE

	@for f in access aliases canonical main.cf master.cf \
		regexp_table relocated transport virtual ; do \
			${INSTALL} -C -o root -g wheel -m 0644 \
			${WRKSRC}/conf/$$f ${PREFIX}/etc/postfix/sample-$$f ; \
	done

.if defined(WITH_PCRE)
	@${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/conf/pcre_table \
		${PREFIX}/etc/postfix/sample-pcre_table
.endif

	@for f in sample-aliases.cf sample-canonical.cf \
		sample-debug.cf sample-filter.cf sample-ldap.cf \
		sample-local.cf sample-misc.cf sample-rate.cf \
		sample-regexp.cf sample-relocated.cf sample-resource.cf \
		sample-rewrite.cf sample-smtp.cf sample-smtpd.cf \
		sample-transport.cf sample-virtual.cf ; do \
			${INSTALL} -C -o root -g wheel -m 0644 \
			${WRKSRC}/conf/$$f ${PREFIX}/etc/postfix/$$f ; \
	done

.if defined(WITH_PCRE)
	@${INSTALL} -C -o root -g wheel -m 0644 \
		${WRKSRC}/conf/sample-pcre.cf \
		${PREFIX}/etc/postfix/sample-pcre.cf
.endif

.if defined(WITH_SASL)
	@${INSTALL} -C -o root -g wheel -m 0644 \
		${WRKSRC}/conf/sample-auth.cf \
		${PREFIX}/etc/postfix/sample-auth.cf
.endif

	@${MKDIR} -m 755 ${PREFIX}/libexec/postfix
	@${CHOWN} root:wheel ${PREFIX}/libexec/postfix

	@for f in bounce cleanup error lmtp local master nqmgr pickup \
		pipe qmgr showq smtp smtpd trivial-rewrite ; do \
		${INSTALL} -C -o root -g wheel -m 0755 \
			${WRKSRC}/libexec/$$f \
			${PREFIX}/libexec/postfix/$$f ; \
	done

	@for f in postalias postcat postconf postfix postkick postlog \
		postmap postsuper sendmail ; do \
		${INSTALL} -C -o root -g wheel -m 0755 \
			${WRKSRC}/$$f/$$f ${PREFIX}/sbin/$$f ; \
	done

	@${INSTALL} -C -o root -g maildrop -m 2755 \
		${WRKSRC}/postdrop/postdrop ${PREFIX}/sbin/postdrop

	@for f in ${MAN1} ; do \
		${INSTALL} -C -o root -g wheel -m 0644 \
		${WRKSRC}/man/man1/$$f ${PREFIX}/man/man1/$$f ; \
	done

	@for f in ${MAN5} ; do \
		${INSTALL} -C -o root -g wheel -m 0644 \
		${WRKSRC}/man/man5/$$f ${PREFIX}/man/man5/$$f ; \
	done

	@for f in ${MAN8} ; do \
		${INSTALL} -C -o root -g wheel -m 0644 \
		${WRKSRC}/man/man8/$$f ${PREFIX}/man/man8/$$f ; \
	done

	@${MKDIR} -m 755 /var/spool/postfix
	@${CHOWN} root:wheel /var/spool/postfix

	@${MKDIR} -m 755 ${PREFIX}/share/doc/postfix
	@${INSTALL} -d -m 555 -o root -g wheel ${PREFIX}/share/doc/postfix
	@cd ${WRKSRC} && ${INSTALL_DATA} \
		html/*.html html/*.gif ${PREFIX}/share/doc && \
		${ECHO_MSG} "Installed HTML documentation in ${PREFIX}/share/doc"

	@${ECHO_MSG} "--------------------------------------------------"
	@${ECHO_MSG} "- To replace your existing sendmail with postfix -"
	@${ECHO_MSG} "- type \"make replace\"                          -"
	@${ECHO_MSG} "--------------------------------------------------"

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO_MSG} "===> Activating postfix in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	${ECHO} 'sendmail       ${PREFIX}/sbin/sendmail' > /etc/mail/mailer.conf
	${ECHO} 'send-mail      ${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
	${ECHO} 'mailq          ${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
	${ECHO} 'newaliases     ${PREFIX}/sbin/sendmail' >>/etc/mail/mailer.conf
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
