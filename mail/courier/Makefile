PORTNAME=	courier
PORTVERSION=	1.5.1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	bsd@dino.sk
COMMENT=	Courier SMTP IMAP POP3 HTTP mail server suite
WWW=		https://www.Courier-MTA.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base \
		gpg2:security/gnupg \
		wget:ftp/wget
LIB_DEPENDS=	libcourier-unicode.so:devel/courier-unicode \
		libgdbm.so:databases/gdbm \
		libidn2.so:dns/libidn2 \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool \
		ca_root_nss>=3.*:security/ca_root_nss \
		courierauthconfig:security/courier-authlib-base \
		p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR \
		wget:ftp/wget

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

IMAGEURL?=		/webmail
CACHEOWN?=		pop
MAILDROPDEFAULT?=	./Maildir

# End of user-serviceable variables

MAILOWN?=	courier
MAILGRP?=	courier
MAILUID?=	465
MAILGID?=	465
SYSCONFDIR=	${ETCDIR}/courier
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/mime.types
WITH_TRANSPORT=	local esmtp dsn

USES=		fam gettext gmake libtool localbase perl5 pkgconfig shebangfix \
		ssl tar:bzip2
USE_RC_SUBR=	courier
USE_SUBMAKE=	yes
SHEBANG_FILES=	courier/filters/perlfilter/perlfilter-ratelimit.pl \
		courier/filters/perlfilter/perlfilter-wrapper.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--disable-root-check \
		--enable-imageurl=${IMAGEURL} \
		--enable-mimetypes=${MIMETYPES} \
		--enable-syslog=1 \
		--enable-unicode \
		--enable-use-flock \
		--enable-utf7-folder-encoding \
		--enable-workarounds-for-imap-client-bugs \
		--libexecdir=${LIBEXECDIR} \
		--localstatedir=${LOCALSTATEDIR} \
		--program-transform-name=s,^,, \
		--sysconfdir=${SYSCONFDIR} \
		--with-cachedir=${CACHEDIR} \
		--with-cacheowner=${CACHEOWN} \
		--with-calendardir=${CALENDIR} \
		--with-db=gdbm \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--with-etcdir=${ETCDIR} \
		--with-mailgid=${MAILGID} \
		--with-mailgroup=${MAILGRP} \
		--with-mailuid=${MAILUID} \
		--with-mailuser=${MAILOWN} \
		--with-mydatadir=${SYSCONFDIR} \
		--with-notice=unicode \
		--with-paranoid-smtpext \
		--with-transport='${WITH_TRANSPORT}'
INSTALL_TARGET=	install-strip install-perms

CONFLICTS=	courier-imap-2.* couriermlm-0.* exim-4.* maildrop-1.* \
		panda-imap-201* postfix-1.* postfix-2.* qmail-*-1.* qmail-1.* \
		sendmail-*-8.* sendmail-8.* smail-3.* sqwebmail-3.* zmailer-2.*

ETCDIR=		${PREFIX}/etc
SUB_FILES+=	crontab pkg-message sharedindexupdate
SUB_LIST:=	${PLIST_SUB}

PLIST_SUB+=	BINGRP="${BINGRP}" \
		BINOWN="${BINOWN}" \
		CACHEDIR="${CACHEDIR}" \
		CACHEOWN="${CACHEOWN}" \
		CALENDIR="${CALENDIR}" \
		LOCALSTATEDIR="${LOCALSTATEDIR}" \
		MAILGID="${MAILGID}" \
		MAILGRP="${MAILGRP}" \
		MAILOWN="${MAILOWN}" \
		MAILUID="${MAILUID}" \
		SHAREGRP="${SHAREGRP}" \
		SHAREOWN="${SHAREOWN}"

OPTIONS_DEFINE=		CERTSDIR DOCS IPV6 LDAP MAILCONF PROCMAIL SENDFAX UUCP
OPTIONS_DEFAULT=	SYSTEMALIASES WEBMAILRSENT
OPTIONS_GROUP=		WEBMAIL
OPTIONS_GROUP_WEBMAIL=	GNUPG WEBMAILFLAGS WEBMAILRSENT WEBMAILXFACE
OPTIONS_RADIO=		ALIASES SPELL
OPTIONS_RADIO_ALIASES=	EMPTYALIASES SYSTEMALIASES
OPTIONS_RADIO_SPELL=	ASPELL ISPELL
OPTIONS_SUB=		yes

ASPELL_DESC=		ASpell support for WebMail
ISPELL_DESC=		ISpell support for WebMail
CERTSDIR_DESC=		separate .pem directory for certificates
EMPTYALIASES_DESC=	create empty aliases file
GNUPG_DESC=		GNU Privacy Guard support for WebMail
LDAP_DESC=		LDAP-based mail aliasing support
MAILCONF_DESC=		modify mailer.conf to use courier instead of sendmail
PROCMAIL_DESC=		Procmail local delivery support
SENDFAX_DESC=		mgetty+sendfax support
SYSTEMALIASES_DESC=	symlink system /etc/aliases
UUCP_DESC=		UUCP support
WEBMAILFLAGS_DESC=	webmail show flags patch
WEBMAILRSENT_DESC=	enable Autorename Sent folder
WEBMAILXFACE_DESC=	experimental webmail X-Face patch

ASPELL_BUILD_DEPENDS=	aspell:textproc/aspell
ASPELL_RUN_DEPENDS=	aspell:textproc/aspell
ASPELL_CONFIGURE_ON=	--with-ispell=${LOCALBASE}/bin/aspell

ISPELL_BUILD_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_CONFIGURE_ON=	--with-ispell=${LOCALBASE}/bin/ispell

CERTSDIR_CONFIGURE_ON=	--with-certsdir=${SYSCONFDIR}/.pem
CERTSDIR_CONFIGURE_OFF=	--with-certsdir=${SYSCONFDIR}
CERTSDIR_SUB_LIST=	CERTSDIRPATH="${SYSCONFDIR}/.pem"
CERTSDIR_SUB_LIST_OFF=	CERTSDIRPATH="${SYSCONFDIR}"

GNUPG_RUN_DEPENDS=	gpg2:security/gnupg
GNUPG_CONFIGURE_ENV=	GPG="${LOCALBASE}/bin/gpg2"

IPV6_CONFIGURE_WITH=	ipv6

LDAP_RUN_DEPENDS=	${LOCALBASE}/lib/courier-authlib/libauthldap.so:net/courier-authlib-ldap
LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldapaliasd

MAILCONF_SUB_LIST=	MAILCONFACT="y"
MAILCONF_SUB_LIST_OFF=	MAILCONFACT="n"

PROCMAIL_BUILD_DEPENDS=	procmail:mail/procmail
PROCMAIL_RUN_DEPENDS=	procmail:mail/procmail

SENDFAX_BUILD_DEPENDS=	pnmscale:graphics/netpbm \
			sendfax:comms/mgetty+sendfax
SENDFAX_RUN_DEPENDS=	pnmscale:graphics/netpbm \
			sendfax:comms/mgetty+sendfax
SENDFAX_USES=		ghostscript
SENDFAX_VARS=		WITH_TRANSPORT+=fax

UUCP_BUILD_DEPENDS=	uux:net/freebsd-uucp
UUCP_RUN_DEPENDS=	uux:net/freebsd-uucp
UUCP_VARS=		WITH_TRANSPORT+=uucp

WEBMAILFLAGS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-libs__sqwebmail__folder.c \
				${FILESDIR}/extra-patch-libs__sqwebmail__maildir.c \
				${FILESDIR}/extra-patch-libs__sqwebmail__maildir.h \
				${FILESDIR}/extra-patch-libs__sqwebmail__images__sqwebmail.css

WEBMAILRSENT_CONFIGURE_ENABLE=	autorenamesent

WEBMAILXFACE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-libs__sqwebmail__msg2html.c

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MASPELL} && !${PORT_OPTIONS:MISPELL}
CONFIGURE_ARGS+=	--without-ispell
.endif

.include "${.CURDIR}/Makefile.doc"

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

_CNFFILES=	esmtpd.cnf \
		imapd.cnf \
		pop3d.cnf

_DISTEXFILES=	courierd.dist \
		esmtpd-msa.dist \
		esmtpd-ssl.dist \
		esmtpd.dist \
		faxcoverpage.tr.dist \
		faxnotifyrc.dist \
		faxrc.dist \
		imapd-ssl.dist \
		imapd.dist \
		ldapaddressbook.dist \
		ldapaliasrc.dist \
		pop3d-ssl.dist \
		pop3d.dist \
		sqwebmaild.dist \
		webmlmrc.dist

pre-patch:
	${CP} ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -i '' -e 's|#! perl|#!${PERL}|g' \
		${WRKSRC}/webadmin/*.pl \
		${WRKSRC}/webadmin/*.pl.in \
		${WRKSRC}/courier/webadmin/*.pl \
		${WRKSRC}/courier/webadmin/*.pl.in
	${REINPLACE_CMD} -e 's|^PROG=\./|PROG=exec ./|g' \
		${WRKSRC}/courier/module.*/courier.config
	${REINPLACE_CMD} -e 's|@mydatadir@|@sysconfdir@|g' \
		${WRKSRC}/*/*/mk*cert.*
	${REINPLACE_CMD} -e 's|^\(TLS_CERTFILE=\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	${REINPLACE_CMD} -e 's|^\(TLS_DHPARAMS=\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	${REINPLACE_CMD} -e 's|^\(RANDFILE[[:space:]]*=[[:space:]]*\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*/*.cnf.openssl.in
	${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) \(.$$$$file.\)|${INSTALL_MAN} \1|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/*/Makefile.in \
		${WRKSRC}/*/*/Makefile.in \
		${WRKSRC}/*/*/*/Makefile.in
	${REINPLACE_CMD} -e 's|^\(INSTALL_STRIP_PROGRAM=\).*$$|\1"${INSTALL_PROGRAM} -s"|' \
			-e 's|; ldapaliasd="yes"||' \
		${WRKSRC}/configure \
		${WRKSRC}/*/configure \
		${WRKSRC}/*/*/configure \
		${WRKSRC}/*/*/*/configure
	${REINPLACE_CMD} -E -e 's/(root|bin)[[:space:]]*bin/root	wheel/g' \
		${WRKSRC}/courier/perms.sh.in
	${REINPLACE_CMD} '/^courieresmtp_LDADD =/s/$$/ -lcourierauth/' \
		${WRKSRC}/courier/module.esmtp/Makefile.in
# Avoid conflict with C++20 <version> by adding .txt suffix
	${REINPLACE_CMD} -i .c++20 's/>version$$/&.txt/' ${WRKSRC}/configure
	${FIND} ${WRKSRC} -name configure -exec ${REINPLACE_CMD} \
		-i .c++20 '/^version.*cat/s,/version,&.txt,' {} +

post-build:
	${PERL} -pi -e 's|^(auth)\s+(required).*|$$1\t\t$$2\tpam_unix.so\ttry_first_pass|g;' \
		    -e 's|^(account)\s+(required).*|$$1 \t$$2\tpam_unix.so|g;' \
		    -e 's|^(session)\s+(required).*|$$1 \t$$2\tpam_permit.so|g;' \
		${WRKSRC}/*/*.authpam* \
		${WRKSRC}/*/*/*.authpam*
	${INSTALL} -lrs ${WRKSRC}/libs/gpglib/README.html	${WRKSRC}/libs/gpglib/README.gpglib.html
	${INSTALL} -lrs ${WRKSRC}/libs/imap/BUGS		${WRKSRC}/libs/imap/BUGS.imap
	${INSTALL} -lrs ${WRKSRC}/libs/imap/BUGS.html		${WRKSRC}/libs/imap/BUGS.imap.html
	${INSTALL} -lrs ${WRKSRC}/libs/imap/README.proxy	${WRKSRC}/libs/imap/README.imap.proxy
	${INSTALL} -lrs ${WRKSRC}/libs/imap/README.proxy.html	${WRKSRC}/libs/imap/README.imap.proxy.html
	${INSTALL} -lrs ${WRKSRC}/libs/maildrop/README.html	${WRKSRC}/libs/maildrop/README.maildrop.html
	${INSTALL} -lrs ${WRKSRC}/libs/pcp/README.html		${WRKSRC}/libs/pcp/README.pcp.html
	${INSTALL} -lrs ${WRKSRC}/libs/sqwebmail/BUGS		${WRKSRC}/libs/sqwebmail/BUGS.sqwebmail
	${INSTALL} -lrs ${WRKSRC}/libs/sqwebmail/BUGS.html	${WRKSRC}/libs/sqwebmail/BUGS.sqwebmail.html
	${INSTALL} -lrs ${WRKSRC}/libs/sqwebmail/SECURITY	${WRKSRC}/libs/sqwebmail/SECURITY.sqwebmail
	${INSTALL} -lrs ${WRKSRC}/libs/sqwebmail/SECURITY.html	${WRKSRC}/libs/sqwebmail/SECURITY.sqwebmail.html

post-install:
.for _cfgfile in ${_CNFFILES}
	-${MV} ${STAGEDIR}${SYSCONFDIR}/${_cfgfile} ${STAGEDIR}${SYSCONFDIR}/${_cfgfile:S/.cnf/.cnf.sample/g}
.endfor
.for _cfgfile in ${_DISTEXFILES}
	-${MV} ${STAGEDIR}${SYSCONFDIR}/${_cfgfile} ${STAGEDIR}${SYSCONFDIR}/${_cfgfile:S/.dist/.sample/g}
.endfor
	${INSTALL} -lrs ${STAGEDIR}${SYSCONFDIR}/maildrop ${STAGEDIR}${SYSCONFDIR}/maildropfilter
	${INSTALL_DATA} /dev/null ${STAGEDIR}${SYSCONFDIR}/locallowercase
	${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${SYSCONFDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/html
.endfor
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/htmldoc/* ${STAGEDIR}${DOCSDIR}/html
.endif
	${RM} -r ${STAGEDIR}${DATADIR}/htmldoc
	${CHMOD} -R a+r ${STAGEDIR}${DATADIR}/courierwebadmin
	${CHMOD} -R a-w ${STAGEDIR}${DATADIR} ${STAGEDIR}${LIBEXECDIR}/courier
	${CHMOD} 550 ${STAGEDIR}${LIBEXECDIR}/courier/modules/esmtp/courieresmtp*

post-install-CERTSDIR-on:
	${MKDIR} ${STAGEDIR}${SYSCONFDIR}/.pem

.include <bsd.port.mk>
