# New ports collection makefile for: Courier MTA
# Date created:		17 Oct 2001
# Whom:			Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	courier
PORTVERSION=	0.44.2
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Courier SMTP IMAP POP3 HTTP mail server suite

CONFLICTS=	exim-4.* courier-imap-2.* maildrop-1.* \
		postfix-1.* postfix-2.* \
		qmail-1.* qmail-*-1.* \
		sendmail-8.* sendmail-*-8.* \
		smail-3.* sqwebmail-3.* zmailer-2.*

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=        print/ghostscript-afpl
.else
GSPORT?=        print/ghostscript-gnu
.endif

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam
RUN_DEPENDS=	${LOCALBASE}/share/sysconftool/sysconftool:${PORTSDIR}/devel/sysconftool \
		${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net/p5-Net-CIDR

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

#
# User-serviceable variables
#
# [ There's no need to add trailing ``/''s ]
#
# set IMAGEURL to where on the web server URL the images are found
# set CACHEOWN to who you'd like to own the cache files
# set MAILDROPDEFAULT to what you'd like the $DEFAULT in maildrop to be
#     recomended values are: /var/mail, ./Mailbox or ./Maildir
#
IMAGEURL?=	/webmail
CACHEOWN?=	pop
MAILDROPDEFAULT?=./Maildir
# End of user-serviceable variables
MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465
ETCDIR=		${PREFIX}/etc
SYSCONFDIR=	${ETCDIR}/courier
USERDB=		${ETCDIR}/userdb
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/apache/mime.types:${LOCALBASE}/etc/apache2/mime.types

USE_BZIP2=	yes
USE_SUBMAKE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	REHASH=${SCRIPTDIR}/c_rehash \
		CPPFLAGS='${CPPFLAGS}' \
		LDFLAGS='${LDFLAGS}'
MAKE_ENV:=	${CONFIGURE_ENV}
CONFIGURE_ARGS=	--disable-root-check --with-db=db \
		--enable-syslog=1 --enable-use-flock \
		--program-transform-name=s,^,, \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--with-mailuid=${MAILUID} \
		--with-mailgid=${MAILGID} \
 		--with-etcdir=${ETCDIR} \
		--sysconfdir=${SYSCONFDIR} \
		--with-userdb=${USERDB} \
		--datadir=${DATADIR} \
		--libexecdir=${LIBEXECDIR} \
		--localstatedir=${LOCALSTATEDIR} \
		--enable-mimetypes=${MIMETYPES} \
		--enable-imageurl=${IMAGEURL} \
		--with-cachedir=${CACHEDIR} \
		--with-cacheowner=${CACHEOWN} \
		--with-calendardir=${CALENDIR} \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--enable-workarounds-for-imap-client-bugs
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PKGMESSAGE=	${WRKDIR}/.PKGMESSAGE

INSTALL_TARGET=	install-strip install-perms

PLIST_SUB+=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" \
		MAILOWN="${MAILOWN}" MAILGRP="${MAILGRP}" \
		MAILUID="${MAILUID}" MAILGID="${MAILGID}" \
		CACHEOWN="${CACHEOWN}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		WITH_EXPECT="${WITH_EXPECT:L}" \
		WITH_GNUPG="${WITH_GNUPG:L}" \
		WITH_ASPELL="${WITH_ASPELL:L}" \
		WITH_ISPELL="${WITH_ISPELL:L}" \
		WITH_LDAP="${WITH_LDAP:L}" \
		WITH_MYSQL="${WITH_MYSQL:L}" \
		WITH_PGSQL="${WITH_PGSQL:L}" \
		WITH_VPOPMAIL="${WITH_VPOPMAIL:L}" \
		WITH_PROCMAIL="${WITH_PROCMAIL:L}" \
		WITH_SENDFAX="${WITH_SENDFAX:L}" \
		WITH_UUCP="${WITH_UUCP:L}" \
		WITH_IPV6="${WITH_IPV6:L}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.include "${.CURDIR}/Makefile.man"
.include "${.CURDIR}/Makefile.doc"
.include "${.CURDIR}/Makefile.own"

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_EXPECT=yes		Expect support for WebMail change passwd"
	@${ECHO_MSG} "	WITH_GNUPG=yes		GNU Privacy Guard support for WebMail"
	@${ECHO_MSG} "	WITH_ASPELL=yes		ASpell support for WebMail"
	@${ECHO_MSG} "	WITH_ISPELL=yes		ISpell support for WebMail"
	@${ECHO_MSG} "	WITH_LDAP=yes		OpenLDAP 2.x authentication support"
.if !defined(WANT_OPENLDAP_VER)
	@${ECHO_MSG} "	WANT_OPENLDAP_VER=??	See <bsd.port.mk> for legal values"
.endif
	@${ECHO_MSG} "	WITH_MYSQL=yes		MySQL authentication support"
	@${ECHO_MSG} "	WITH_PGSQL=yes		PostgreSQL authentication support"
	@${ECHO_MSG} "	WITH_VPOPMAIL=yes	VPopMail authentication support"
	@${ECHO_MSG} "	WITH_PROCMAIL=yes	Procmail local delivery support"
	@${ECHO_MSG} "	WITH_SENDFAX=yes	mgetty+sendfax support"
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} "	WITH_GHOSTSCRIPT_AFPL=yes to use AFPL Postscript"
	@${ECHO_MSG} "				interpreter instead of GNU one"
	@${ECHO_MSG} "				for mgetty+sendfax support"
.endif
	@${ECHO_MSG} "	WITH_UUCP=yes		UUCP support"
	@${ECHO_MSG} "	WITH_IPV6=yes		Pv6 support"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	BATCH=yes		To skip INTERACTIVE selection"
	@${ECHO_MSG} "				of above tunables"
	@${ECHO_MSG} ""
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.${PORTNAME}

post-patch:
	@${PERL} -pi -e 's:\@datadir\@:\@sysconfdir\@:g;' \
		${WRKSRC}/*/mk*cert.* \
		${WRKSRC}/*/*/mk*cert.*
	@${PERL} -pi -e 's:^(TLS_CERTFILE=)\@datadir\@:$$1\@sysconfdir\@:g;' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	@${PERL} -pi -e 's:^(RANDFILE = )\@datadir\@\S+:$$1\@sysconfdir\@/random.tmp:g;' \
		${WRKSRC}/*/*.cnf.in \
		${WRKSRC}/*/*/*.cnf.in

pre-configure:
	@${SED}	-e s:%%RC_SUBR%%:${RC_SUBR}: \
		-e s:%%PREFIX%%:${PREFIX}: ${FILESDIR}/courier.sh > ${WRKDIR}/courier.sh
	@${SED}	-e s:%%PREFIX%%:${PREFIX}: ${.CURDIR}/pkg-message > ${WRKDIR}/.PKGMESSAGE
	@${SED}	-e s:%%PREFIX%%:${PREFIX}: ${FILESDIR}/crontab > ${WRKDIR}/crontab

post-build:
	@${PERL} -pi -e 's:^(auth)\s+(required).*:$$1\t\t$$2\tpam_unix.so\ttry_first_pass:g;' \
		     -e 's:^(account)\s+(required).*:$$1 \t$$2\tpam_unix.so:g;' \
		     -e 's:^(session)\s+(required).*:$$1 \t$$2\tpam_permit.so:g;' \
		${WRKSRC}/*/*.authpam* \
		${WRKSRC}/*/*/*.authpam*
	@${LN} -f ${WRKSRC}/gpglib/README.html		${WRKSRC}/gpglib/README.gpglib.html
	@${LN} -f ${WRKSRC}/imap/FAQ			${WRKSRC}/imap/FAQ.imap
	@${LN} -f ${WRKSRC}/imap/FAQ.html		${WRKSRC}/imap/FAQ.imap.html
	@${LN} -f ${WRKSRC}/imap/README			${WRKSRC}/imap/README.imap
	@${LN} -f ${WRKSRC}/imap/README.html		${WRKSRC}/imap/README.imap.html
	@${LN} -f ${WRKSRC}/maildrop/README.html	${WRKSRC}/maildrop/README.maildrop.html
	@${LN} -f ${WRKSRC}/pcp/README.html		${WRKSRC}/pcp/README.pcp.html
	@${LN} -f ${WRKSRC}/webmail/BUGS		${WRKSRC}/webmail/BUGS.webmail
	@${LN} -f ${WRKSRC}/webmail/BUGS.html		${WRKSRC}/webmail/BUGS.webmail.html
	@${LN} -f ${WRKSRC}/webmail/SECURITY		${WRKSRC}/webmail/SECURITY.webmail
	@${LN} -f ${WRKSRC}/webmail/SECURITY.html	${WRKSRC}/webmail/SECURITY.webmail.html

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${LN} -f ${SYSCONFDIR}/maildrop ${SYSCONFDIR}/maildropfilter
	@${INSTALL_DATA} /dev/null ${SYSCONFDIR}/locallowercase
	@${INSTALL_DATA} ${WRKDIR}/crontab ${PREFIX}/etc/courier/
	@${INSTALL_SCRIPT} ${WRKDIR}/courier.sh ${PREFIX}/etc/rc.d/
.for file in ${OWNER0}
	@-${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/${file}
.endfor
	@${GREP} '^@exec ' ${TMPPLIST} \
		| ${SED} -e 's:^@exec ::' -e 's:%D:${PREFIX}:g' \
		> ${WRKDIR}/.PLIST.exec \
		&& ${SH} ${WRKDIR}/.PLIST.exec
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}/html
	@${INSTALL_DATA} ${DATADIR}/htmldoc/* ${DOCSDIR}/html
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${RM} -rf ${DATADIR}/htmldoc
	@for F in ${MANPREFIX}/man/man[1-9ln]/*; \
		do ${CHMOD} ${MANMODE} $$F; \
	done
	@${CHOWN} -Rh ${MANOWN}:${MANGRP} ${MANPREFIX}/man/man[1-9ln]
	@${CHOWN} -Rh ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHMOD} -R a+r ${DATADIR}/courierwebadmin
	@${CHMOD} -R a-w ${DATADIR}
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.else
	@${ECHO_MSG} "	To activate Courier in /etc/mail/mailer.conf or to"
	@${ECHO_MSG} "	replace {sendmail,mailq,newaliases} with Courier"
	@${ECHO_MSG} "	versions execute the following as root user:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "PKG_PREFIX=\"${PREFIX}\" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL"
	@${ECHO_MSG} ""
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
