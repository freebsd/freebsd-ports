# New ports collection makefile for: Courier MTA
# Date created:		17 Oct 2001
# Whom:			Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	courier
PORTVERSION=	0.39.3
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	yds@CoolRat.org

RUN_DEPENDS=	${LOCALBASE}/share/sysconftool/sysconftool:${PORTSDIR}/devel/sysconftool \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/CIDR.pm:${PORTSDIR}/net/p5-Net-CIDR

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
MAILUID=	62
MAILGID=	62
ETCDIR=		${PREFIX}/etc
SYSCONFDIR=	${ETCDIR}/courier
USERDB=		${ETCDIR}/userdb
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/apache/mime.types:${LOCALBASE}/etc/apache2/mime.types

USE_SUBMAKE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
CONFIGURE_ARGS=	--disable-root-check --with-db=db \
		--enable-syslog=1 --enable-use-flock \
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
CONFIGURE_ENV=	PATH="${PATH}:${SCRIPTDIR}"

# Respect the make.conf(5) NOUUCP setting
WITH_TRANSPORT=	local esmtp dsn
.if defined(NOUUCP)
PLIST_SUB+=	SUB_UUCP="@comment "
.else
WITH_TRANSPORT+=uucp
PLIST_SUB+=	SUB_UUCP=""
.endif

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
		WITH_LDAP1="${WITH_LDAP1:L}" \
		WITH_LDAP2="${WITH_LDAP2:L}" \
		WITH_MYSQL="${WITH_MYSQL:L}" \
		WITH_PGSQL="${WITH_PGSQL:L}" \
		WITH_VPOPMAIL="${WITH_VPOPMAIL:L}" \
		WITH_PROCMAIL="${WITH_PROCMAIL:L}" \
		WITH_SENDFAX="${WITH_SENDFAX:L}" \
		WITH_IPV6="${WITH_IPV6:L}" \
		WITH_TRANSPORT="${WITH_TRANSPORT}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.include "${.CURDIR}/Makefile.man"
.include "${.CURDIR}/Makefile.doc"
.include "${.CURDIR}/Makefile.own"

pre-everything::
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
	@${SED} s:%%PREFIX%%:${PREFIX}: \
		${.CURDIR}/pkg-message \
		> ${WRKDIR}/.PKGMESSAGE
	@${SED} s:%%PREFIX%%:${PREFIX}: \
		${FILESDIR}/crontab \
		> ${WRKDIR}/crontab

# patch around a bug in autoconf where the INSTALL macro does
# not get set properly in directories more than one level deep
post-build:
	@${PERL} -pi -e 's:^INSTALL = \.\./:INSTALL = ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP}:;' \
		`${GREP} -rl '^INSTALL = \.\./' ${WRKSRC}/* | ${GREP} '/Makefile$$'`
	@${PERL} -pi -e 's:^TAR = gtar$$:TAR = ${TAR}:g;' \
		`${GREP} -rl '^TAR = gtar$$' ${WRKSRC}/* | ${GREP} '/Makefile$$'`
	@${PERL} -pi -e 's:^(auth)\s+(required).*:$$1\t\t$$2\tpam_unix.so\ttry_first_pass:g; \
			s:^(account)\s+(required).*:$$1 \t$$2\tpam_unix.so:g; \
			s:^(session)\s+(required).*:$$1 \t$$2\tpam_permit.so:g;' \
		${WRKSRC}/*/*.authpam* \
		${WRKSRC}/*/*/*.authpam*
	@${LN} ${WRKSRC}/gpglib/README.html	${WRKSRC}/gpglib/README.gpglib.html
	@${LN} ${WRKSRC}/imap/FAQ		${WRKSRC}/imap/FAQ.imap
	@${LN} ${WRKSRC}/imap/FAQ.html		${WRKSRC}/imap/FAQ.imap.html
	@${LN} ${WRKSRC}/imap/README		${WRKSRC}/imap/README.imap
	@${LN} ${WRKSRC}/imap/README.html	${WRKSRC}/imap/README.imap.html
	@${LN} ${WRKSRC}/maildrop/README.html	${WRKSRC}/maildrop/README.maildrop.html
	@${LN} ${WRKSRC}/pcp/README.html	${WRKSRC}/pcp/README.pcp.html
	@${LN} ${WRKSRC}/webmail/BUGS		${WRKSRC}/webmail/BUGS.webmail
	@${LN} ${WRKSRC}/webmail/BUGS.html	${WRKSRC}/webmail/BUGS.webmail.html
	@${LN} ${WRKSRC}/webmail/SECURITY	${WRKSRC}/webmail/SECURITY.webmail
	@${LN} ${WRKSRC}/webmail/SECURITY.html	${WRKSRC}/webmail/SECURITY.webmail.html

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@strip ${PREFIX}/libexec/courier/modules/*/*
	@${LN} -f ${SYSCONFDIR}/maildrop ${SYSCONFDIR}/maildropfilter
	@${INSTALL_DATA} /dev/null ${SYSCONFDIR}/locallowercase
	@${INSTALL_SCRIPT} ${FILESDIR}/courier.sh ${PREFIX}/etc/rc.d
	@${INSTALL_DATA} ${WRKDIR}/crontab ${PREFIX}/etc/courier/
.for file in ${OWNER0}
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/${file}
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
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ""

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
