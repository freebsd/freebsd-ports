# New ports collection makefile for:	zmailer
# Date created:		4 January 1999
# Whom:			Alex Perel <veers@disturbed.net>
#
# $FreeBSD$
#

PORTNAME=	zmailer
PORTVERSION=	2.99.51
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/mail/zmailer/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fully functional fast, robust SMTP server and transport agent

CONFLICTS=	courier-0.* postfix-1.* postfix-2.* sendmail-8.* sendmail-*-8.* smail-3.*
GNU_CONFIGURE=	yes
USE_GCC=	2.95

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS=	--with-openssl
.else
CONFIGURE_ARGS=	--without-openssl
.endif

CONFIGURE_ARGS+=--prefix=${PREFIX}/ \
		--with-bundled-libresolv \
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
		--with-ta-mmap

MAN1=		rmail.1 vacation.1 zmailer.1 zmsh.1 mboxpath.1 ssl.1 mailq.1 \
		mailrm.1 newaliases.1
MAN3=		zmailer.3
MAN5=		aliases.5
MAN8=		hold.8 router.8 scheduler.8 sendmail.8 sm.8 smtp.8 \
		smtpserver.8 mprobe.8 expirer.8 errormail.8 mailbox.8 \
		manual-expirer.8

# local variable
# this pipe is run before bsd.port.mk is brought in - therefore it is
# not possible to use ${SED}
DOMAIN!=	/bin/hostname | /usr/bin/sed -e "s:^"`/bin/hostname -s`\.*::g
.if (${DOMAIN} == "")
DOMAIN=		"mydomain.com"
.endif
PKGMESSAGE=	${WRKDIR}/MESSAGE

post-configure:
	${SED} -e s:@PREFIX@:${PREFIX}:g -e s:@PORTSDIR@:${PORTSDIR}:g \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/zmailer.sh.sample \
		 ${PREFIX}/etc/rc.d/zmailer.sh.sample

	${CAT} ${PKGMESSAGE} | ${SED} -e s:@PREFIX@:${PREFIX}:g \
		-e s:@PORTSDIR@:${PORTSDIR}:g

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

.include <bsd.port.mk>
