# New ports collection makefile for: Courier MTA
# Date created:		17 Oct 2001
# Whom:			Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	courier
PORTVERSION=	0.45.4
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	yds@CoolRat.org
COMMENT=	Courier SMTP IMAP POP3 HTTP mail server suite

CONFLICTS=	exim-4.* courier-imap-2.* maildrop-1.* \
		postfix-1.* postfix-2.* \
		qmail-1.* qmail-*-1.* \
		sendmail-8.* sendmail-*-8.* \
		smail-3.* sqwebmail-3.* zmailer-2.*

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam
RUN_DEPENDS=	${LOCALBASE}/share/sysconftool/sysconftool:${PORTSDIR}/devel/sysconftool \
		${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net-mgmt/p5-Net-CIDR

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
WITH_TRANSPORT=	local esmtp dsn

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
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
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
		--with-transport='${WITH_TRANSPORT}' \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--enable-workarounds-for-imap-client-bugs

PKGMESSAGE=	${WRKDIR}/.PKGMESSAGE

INSTALL_TARGET=	install-strip install-perms

PLIST_SUB+=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" \
		MAILOWN="${MAILOWN}" MAILGRP="${MAILGRP}" \
		MAILUID="${MAILUID}" MAILGID="${MAILGID}" \
		CACHEOWN="${CACHEOWN}"

OPTIONS+=EXPECT "Expect support for WebMail change passwd"
.if exists(${LOCALBASE}/bin/expect) || defined(WITH_EXPECT)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=GNUPG "GNU Privacy Guard support for WebMail"
.if exists(${LOCALBASE}/bin/gpg) || defined(WITH_GNUPG)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=ASPELL "ASpell support for WebMail  / mutually"
.if exists(${LOCALBASE}/bin/aspell) || defined(WITH_ASPELL)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=ISPELL "ISpell support for WebMail  \ exclusive"
.if exists(${LOCALBASE}/bin/ispell) || defined(WITH_ISPELL)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=OPENLDAP "OpenLDAP 2.x authentication support"
.if (exists(${LOCALBASE}/lib/libldap.so.2) && exists(${LOCALBASE}/lib/liblber.so.2)) || defined(WITH_OPENLDAP)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=MYSQL "MySQL authentication support"
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14) || defined(WITH_MYSQL)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=PGSQL "PostgreSQL authentication support"
.if exists(${PGSQLBASE}/lib/libpq.so.3) || defined(WITH_PGSQL)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=VCHKPW "VPopMail authentication support"
.if exists(${LOCALBASE}/vpopmail/lib/libvpopmail.a) || defined(WITH_VCHKPW)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=PROCMAIL "Procmail local delivery support"
.if exists(${LOCALBASE}/bin/procmail) || defined(WITH_PROCMAIL)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=SENDFAX "mgetty+sendfax support"
.if exists(${LOCALBASE}/sbin/sendfax) && exists(${LOCALBASE}/bin/pnmscale) && exists(${LOCALBASE}/bin/gs) || defined(WITH_SENDFAX)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=UUCP "UUCP support"
.if exists(/usr/bin/uux) || exists(${LOCALBASE}/bin/uux) || defined(WITH_UUCP)
OPTIONS+=on
.else
OPTIONS+=off
.endif

OPTIONS+=IPV6 "IPv6 support"
.if defined(WITH_IPV6) && !defined(WITHOUT_IPV6)
OPTIONS+=on
.else
OPTIONS+=off
.endif

.include "${.CURDIR}/Makefile.man"
.include "${.CURDIR}/Makefile.doc"
.include "${.CURDIR}/Makefile.own"
.include <bsd.port.pre.mk>

.if defined(WITH_EXPECT) && !defined(WITHOUT_EXPECT)
BUILD_DEPENDS+=	expect:${PORTSDIR}/lang/expect
PLIST_SUB+=	SUB_EXPECT=""
.else
CONFIGURE_ARGS+=--disable-changepass
PLIST_SUB+=	SUB_EXPECT="@comment "
.endif

.if defined(WITH_GNUPG) && !defined(WITHOUT_GNUPG)
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
.endif

.if defined(WITH_ASPELL) && !defined(WITHOUT_ASPELL) && !defined(WITH_ISPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/aspell
.endif

.if defined(WITH_ISPELL) && !defined(WITHOUT_ISPELL) && !defined(WITH_ASPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/ispell
.endif

.if defined(WITH_ASPELL) && defined(WITH_ISPELL)
BROKEN=	ASpell and ISpell are mutually exclusive.
.endif

.if !defined(WITH_ASPELL) && !defined(WITH_ISPELL)
CONFIGURE_ARGS+=--without-ispell
.endif

.if defined(WITH_OPENLDAP) && !defined(WITHOUT_OPENLDAP)
PKGNAMESUFFIX!=	${ECHO} ${PKGNAMESUFFIX}-ldap
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-authldap
PLIST_SUB+=	SUB_LDAP=""
.else
CONFIGURE_ARGS+=--without-authldap
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

.if defined(WITH_MYSQL) && !defined(WITHOUT_MYSQL) && !defined(WITH_VCHKPW)
.if exists(${LOCALBASE}/vpopmail/lib/libvpopmail.a)
BROKEN+=	VPopMail and MySQL are mutually exclusive.\
		Uninstall VPopMail if you want MySQL authentication.
.endif
PKGNAMESUFFIX!=	${ECHO} ${PKGNAMESUFFIX}-mysql
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-authmysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql
PLIST_SUB+=	SUB_MYSQL=""
.else
CONFIGURE_ARGS+=--without-authmysql
PLIST_SUB+=	SUB_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
PKGNAMESUFFIX!=	${ECHO} ${PKGNAMESUFFIX}-pgsql
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--with-authpgsql \
		--with-pgsql-libs=${PGSQLBASE}/lib \
		--with-pgsql-includes=${PGSQLINCLUDES}
PLIST_SUB+=	SUB_PGSQL=""
.else
CONFIGURE_ARGS+=--without-authpgsql
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if defined(WITH_VCHKPW) && !defined(WITHOUT_VCHKPW) && !defined(WITH_MYSQL)
PKGNAMESUFFIX!=	${ECHO} ${PKGNAMESUFFIX}-vpopmail
BUILD_DEPENDS+=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=--with-authvchkpw
.else
CONFIGURE_ARGS+=--without-authvchkpw
.endif

.if defined(WITH_PROCMAIL) && !defined(WITHOUT_PROCMAIL)
BUILD_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
.endif

.if defined(WITH_SENDFAX) && !defined(WITHOUT_SENDFAX)
USE_GHOSTSCRIPT=yes
SENDFAX_DEPENDS=sendfax:${PORTSDIR}/comms/mgetty+sendfax \
		pnmscale:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS+=	${SENDFAX_DEPENDS}
RUN_DEPENDS+=	${SENDFAX_DEPENDS}
WITH_TRANSPORT+=fax
PLIST_SUB+=	SUB_FAX=""
.else
PLIST_SUB+=	SUB_FAX="@comment "
.endif

.if defined(WITH_UUCP) && !defined(WITHOUT_UUCP)
.if !exists(/usr/bin/uux)
BUILD_DEPENDS+=	uux:${PORTSDIR}/net/freebsd-uucp
RUN_DEPENDS+=	uux:${PORTSDIR}/net/freebsd-uucp
.endif
WITH_TRANSPORT+=uucp
PLIST_SUB+=	SUB_UUCP=""
.else
PLIST_SUB+=	SUB_UUCP="@comment "
.endif

.if defined(WITHOUT_IPV6) || !defined(WITH_IPV6)
CONFIGURE_ARGS+=--without-ipv6
.else
CONFIGURE_ARGS+=--with-ipv6
.endif

pre-everything::
	@${ECHO_MSG} "===> -------------------------------------------"
	@${ECHO_MSG} "===> Run 'make config' to (re)configure the port"
	@${ECHO_MSG} "===> -------------------------------------------"

post-patch:
	@${REINPLACE_CMD} -e 's:@datadir@:@sysconfdir@:g' \
		${WRKSRC}/*/mk*cert.* \
		${WRKSRC}/*/*/mk*cert.*
	@${REINPLACE_CMD} -e 's:^TLS_CERTFILE=@datadir@:TLS_CERTFILE=@sysconfdir@:g' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	@${REINPLACE_CMD} -e 's:^RANDFILE = @datadir@[^[:space:]]*:RANDFILE = @sysconfdir@/random.tmp:g' \
		${WRKSRC}/*/*.cnf.in \
		${WRKSRC}/*/*/*.cnf.in
	@${REINPLACE_CMD} -e 's:"\\$${SHELL} \\$$(install_sh) -c -s":"\\$${BSD_INSTALL_PROGRAM}":' \
		${WRKSRC}/configure \
		${WRKSRC}/*/configure \
		${WRKSRC}/*/*/configure \
		${WRKSRC}/*/*/*/configure

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
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
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
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	@${ECHO_MSG} "	To activate Courier in /etc/mail/mailer.conf or to"
	@${ECHO_MSG} "	replace {sendmail,mailq,newaliases} with Courier"
	@${ECHO_MSG} "	versions execute the following as root user:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "PKG_PREFIX=\"${PREFIX}\" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL"
	@${ECHO_MSG} ""
.else
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
