# New ports collection makefile for:	zmailer
# Date created:		4 January 1999
# Whom:			Alex Perel <veers@disturbed.net>
#
# $FreeBSD$
#

PORTNAME=	zmailer
PORTVERSION=	2.99.56
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/mail/zmailer/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fully functional fast, robust SMTP server and transport agent

CONFLICTS=	courier-0.* postfix-1.* postfix-2.* sendmail-8.* sendmail-*-8.* smail-3.*
GNU_CONFIGURE=	yes
USE_PERL5=	yes

.if defined(WITH_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-openssl
.else
CONFIGURE_ARGS=	--without-openssl
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.006 or better"
.endif

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-EAI_NODATA
.endif

CONFIGURE_ARGS+=--prefix=${PREFIX}/ \
		--with-mailbin=${PREFIX}/sbin \
		--with-mailbox=/var/mail \
		--with-logdir=/var/log/mail \
		--with-zconfig=${PREFIX}/etc/zmailer/zmailer.conf \
		--with-zmailer=${PREFIX}/etc/zmailer/zmailer.conf \
		--with-system-malloc \
		--with-sendmailpath=${PREFIX}/sbin/sendmail \
		--with-rmailpath=${PREFIX}/sbin/rmail \
		--with-mailshare=${PREFIX}/etc/zmailer  \
		--with-mailvar=${PREFIX}/etc/zmailer \
		--with-postoffice=/var/spool/postoffice \
		--with-vacationpath=${PREFIX}/bin/vacation \
		--includedir=${PREFIX}/include \
		--libdir=${PREFIX}/lib \
		--mandir=${PREFIX}/man \
		--with-ta-mmap

MAN1=		rmail.1zm vacation.1zm zmailer.1zm zmsh.1zm mboxpath.1zm mailq.1zm \
		mailrm.1zm newaliases.1zm
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ZMailer::mailq.3
MAN5=		aliases.5zm mailq-m.5zm zdbases.conf.5zm zmailer.conf.5zm
MAN8=		hold.8zm router.8zm scheduler.8zm sendmail.8zm sm.8zm smtp.8zm \
		smtpserver.8zm mprobe.8zm expirer.8zm errormail.8zm mailbox.8zm \
		manual-expirer.8zm manual-rerouter.8zm reroute.8zm

PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/pkg-install

# local variable
# this pipe is run before bsd.port.mk is brought in - therefore it is
# not possible to use ${SED}
DOMAIN!=	/bin/hostname | /usr/bin/sed -e "s:^"`/bin/hostname -s`\.*::g
.if (${DOMAIN} == "")
DOMAIN=		"mydomain.com"
.endif

post-configure:
	${SED} -e s:@PREFIX@:${PREFIX}:g -e s:@PORTSDIR@:${PORTSDIR}:g \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/zmailer.sh.sample \
		 ${PREFIX}/etc/rc.d/zmailer.sh.sample

	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${FILESDIR}/pkg-install.in > \
		${PKGINSTALL}
	@${SETENV} PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

# set up the initial mail.conf with reasonable settings.
	@${ECHO_CMD} "# Where am I?" > ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "orgdomain="${DOMAIN} >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "# Who am I?" >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "hostname="`/bin/hostname -s`'.$$orgdomain' >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "# Who do I claim to be?" >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} 'mydomain=$$orgdomain' >> ${PREFIX}/etc/zmailer/mail.conf.sample

# obtained directly from ports/mail/postfix
# with minor hacks by the originator of this port <veers@disturbed.net>
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
	@if [ -e ${PREFIX}/sbin/mailq ]; then \
		${LN} -s ${PREFIX}/sbin/mailq /usr/bin/mailq; \
	fi
	@${ECHO_MSG} "===> Replacing newaliases"
	@if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.OFF; \
		${CHMOD} 0 /usr/bin/newaliases.OFF; \
	fi
	@if [ -e ${PREFIX}/sbin/newaliases ]; then \
		${LN} -s ${PREFIX}/sbin/newaliases /usr/bin/newaliases; \
	fi
	@${ECHO_MSG} "===> Replacing rmail"
	@if [ -e /bin/rmail ]; then \
		${MV} -f /bin/rmail /bin/rmail.OFF; \
		${CHMOD} 0 /bin/rmail.OFF; \
	fi
	@if [ -e ${PREFIX}/sbin/rmail ]; then \
		${LN} -s ${PREFIX}/sbin/rmail /bin/rmail; \
	fi

.include <bsd.port.post.mk>
