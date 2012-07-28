# New ports collection makefile for:	zmailer
# Date created:		4 January 1999
# Whom:			Alex Perel <veers@disturbed.net>
#
# $FreeBSD$
#

PORTNAME=	zmailer
PORTVERSION=	2.99.57
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/mail/zmailer/src/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fully functional fast robust SMTP server and transport agent

CONFLICTS=	courier-0.* postfix-1.* postfix-2.* sendmail-8.* sendmail-*-8.* smail-3.*

OPTIONS=	SSL "Enable SSL support" ON

GNU_CONFIGURE=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES=	${FILESDIR}/extra-utmpx
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=	--without-openssl
.else
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS=	--with-openssl
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
		--with-ta-mmap

MAN1=		rmail.1zm vacation.1zm zmailer.1zm zmsh.1zm mboxpath.1zm mailq.1zm \
		mailrm.1zm newaliases.1zm
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ZMailer::mailq.3
MAN5=		aliases.5zm mailq-m.5zm zdbases.conf.5zm zmailer.conf.5zm
MAN8=		hold.8zm router.8zm scheduler.8zm sendmail.8zm sm.8zm smtp.8zm \
		smtpserver.8zm mprobe.8zm expirer.8zm errormail.8zm mailbox.8zm \
		manual-expirer.8zm manual-rerouter.8zm reroute.8zm

SUB_FILES=	pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install
USE_RC_SUBR=	zmailer.sh

# local variable (we can't use ${SED} here)
DOMAIN!=	/bin/hostname | ${SED} -e "s:^"`/bin/hostname -s`"\.*::g"
.if (${DOMAIN} == "")
DOMAIN=		"mydomain.com"
.endif

pre-install:
	cd ${WRKSRC}/man && make install

post-install:
	@${SETENV} PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
# set up the initial mail.conf with reasonable settings.
	@${ECHO_CMD} "# Where am I?" > ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "orgdomain="${DOMAIN} >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "# Who am I?" >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "hostname="`/bin/hostname -s`'.$$orgdomain' >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} "# Who do I claim to be?" >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${ECHO_CMD} 'mydomain=$$orgdomain' >> ${PREFIX}/etc/zmailer/mail.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
