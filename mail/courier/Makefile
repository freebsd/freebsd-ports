# New ports collection makefile for: Courier MTA
# Date created:		17 Oct 2001
# Whom:			Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	courier
PORTVERSION=	0.37.0
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.courier-mta.org/beta/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	yds@CoolRat.org

#BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/sysconftool.m4:${PORTSDIR}/devel/sysconftool
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/CIDR.pm:${PORTSDIR}/net/p5-Net-CIDR

#
# User-serviceable variables
#
# [ There's no need to add trailing ``/''s ]
#
# set IMAGEURL to where on the web server URL the images are found
# set CACHEOWNER to who you'd like to own the cache files
# set MAILDROPDEFAULT to what you'd like the $DEFAULT in maildrop to be
#     recomended values are: /var/mail, ./Mailbox or ./Maildir
#
IMAGEURL?=	/webmail
CACHEOWNER?=	pop
MAILDROPDEFAULT?=./Maildir
# End of user-serviceable variables
MAILUSER=	courier
MAILGROUP=	courier
MAILUID=	62
MAILGID=	62
ETCDIR=		${PREFIX}/etc
SYSCONFDIR=	${ETCDIR}/courier
USERDB=		${ETCDIR}/userdb
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/apache/mime.types

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
CONFIGURE_ARGS=	--disable-root-check --with-db=db \
		--enable-syslog=1 --enable-use-flock \
		--with-mailuser=${MAILUSER} \
		--with-mailgroup=${MAILGROUP} \
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
		--with-cacheowner=${CACHEOWNER} \
		--with-calendardir=${CALENDIR} \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--enable-workarounds-for-imap-client-bugs
CONFIGURE_ENV=	PATH="${PATH}:${SCRIPTDIR}"

PKGMESSAGE=	${WRKDIR}/.PKGMESSAGE

INSTALL_TARGET=	install-strip

PLIST_SUB+=	CACHEOWNER="${CACHEOWNER}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.include "${.CURDIR}/Makefile.man"
.include "${.CURDIR}/Makefile.doc"

pre-everything:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.courier

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-patch:
	@${PERL} -pi -e 's:\@datadir\@:\@sysconfdir\@:g;' \
		${WRKSRC}/*/mk*cert.* \
		${WRKSRC}/*/*/mk*cert.*
	@${PERL} -pi -e 's:^(TLS_CERTFILE=)\@datadir\@:$$1\@sysconfdir\@:g;' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	@${PERL} -pi -e 's:^(RANDFILE = )\@datadir\@:$$1\@sysconfdir\@:g;' \
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
	@${GREP} '^@exec ' ${TMPPLIST} \
		| ${SED} -e 's:^@exec ::' -e 's:%D:${PREFIX}:g' \
		> ${WRKDIR}/.PLIST.exec \
		&& ${SH} ${WRKDIR}/.PLIST.exec
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR}/html
	@${INSTALL_DATA} ${DATADIR}/htmldoc/* ${DOCSDIR}/html
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${RM} -rf ${DATADIR}/htmldoc
	@for F in ${MANPREFIX}/man/man[1-9ln]/*; \
		do ${CHMOD} ${MANMODE} $$F; \
	done
	@${CHOWN} -R ${MANOWN}:${MANGRP} ${MANPREFIX}/man/man[1-9ln]
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHMOD} -R a-w ${DATADIR}
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
