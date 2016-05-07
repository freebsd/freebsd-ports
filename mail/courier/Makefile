# Created by: Yarema <yds@CoolRat.org>
# $FreeBSD$

PORTNAME=	courier
PORTVERSION=	0.65.3
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	bsd@dino.sk
COMMENT=	Courier SMTP IMAP POP3 HTTP mail server suite

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base
LIB_DEPENDS=	libpcre.so:devel/pcre
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base \
		${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool \
		${LOCALBASE}/etc/mime.types:misc/mime-support \
		p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR \
		ca_root_nss>=3.*:security/ca_root_nss

CONFLICTS=	courier-imap-2.* couriermlm-0.* \
		exim-4.* maildrop-1.* \
		postfix-1.* postfix-2.* \
		qmail-*-1.* qmail-1.* \
		sendmail-*-8.* sendmail-8.* \
		smail-3.* sqwebmail-3.* \
		zmailer-2.*

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
LIBEXECDIR=	${PREFIX}/libexec
LOCALSTATEDIR=	/var/spool/courier
CACHEDIR=	/var/spool/webmail
CALENDIR=	/var/spool/calendar
MIMETYPES=	${LOCALBASE}/etc/mime.types
WITH_TRANSPORT=	local esmtp dsn

USES=		fam gettext gmake libtool perl5 pkgconfig tar:bzip2
USE_OPENSSL=	yes
USE_SUBMAKE=	yes
USE_RC_SUBR=	courier

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-root-check \
		--with-db=db \
		--enable-syslog=1 --enable-use-flock \
		--program-transform-name=s,^,, \
		--enable-utf7-folder-encoding \
		--enable-unicode \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--with-mailuid=${MAILUID} \
		--with-mailgid=${MAILGID} \
		--with-etcdir=${ETCDIR} \
		--sysconfdir=${SYSCONFDIR} \
		--datadir=${DATADIR} \
		--libexecdir=${LIBEXECDIR} \
		--localstatedir=${LOCALSTATEDIR} \
		--enable-mimetypes=${MIMETYPES} \
		--enable-imageurl=${IMAGEURL} \
		--with-cachedir=${CACHEDIR} \
		--with-cacheowner=${CACHEOWN} \
		--with-calendardir=${CALENDIR} \
		--with-certsdir=${SYSCONFDIR} \
		--with-transport='${WITH_TRANSPORT}' \
		--with-default-maildrop=${MAILDROPDEFAULT} \
		--with-paranoid-smtpext \
		--enable-workarounds-for-imap-client-bugs
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip install-perms

PLIST_SUB+=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" \
		MAILOWN="${MAILOWN}" MAILGRP="${MAILGRP}" \
		MAILUID="${MAILUID}" MAILGID="${MAILGID}" \
		CACHEOWN="${CACHEOWN}" CACHEDIR="${CACHEDIR}" \
		CALENDIR="${CALENDIR}" LOCALSTATEDIR="${LOCALSTATEDIR}"
SUB_LIST:=	${PLIST_SUB}
SUB_FILES+=	pkg-message crontab sharedindexupdate
#SUB_FILES+=	pkg-install pkg-message crontab sharedindexupdate

OPTIONS_DEFINE=	LDAP PROCMAIL SENDFAX UUCP IPV6 MAILDROPFLAGS DOCS
OPTIONS_GROUP=	WEBMAIL
#OPTIONS_GROUP=	SYSTEM WEBMAIL
#OPTIONS_GROUP_SYSTEM=	RCCONF MAILCONF PERIODIC
OPTIONS_GROUP_WEBMAIL=	GNUPG WEBMAILRSENT WEBMAILFLAGS WEBMAILXFACE
OPTIONS_RADIO=	ALIASES SPELL
OPTIONS_RADIO_ALIASES=	SYSTEMALIASES EMPTYALIASES
OPTIONS_RADIO_SPELL=	ASPELL ISPELL
OPTIONS_DEFAULT=WEBMAILRSENT SYSTEMALIASES

LDAP_DESC=	LDAP-based mail aliasing support
GNUPG_DESC=	GNU Privacy Guard support for WebMail
ASPELL_DESC=	ASpell support for WebMail
ISPELL_DESC=	ISpell support for WebMail
PROCMAIL_DESC=	Procmail local delivery support
SENDFAX_DESC=	mgetty+sendfax support
UUCP_DESC=	UUCP support
MAILDROPFLAGS_DESC=	maildrop set flags patch
WEBMAILRSENT_DESC=	enable Autorename Sent folder
WEBMAILFLAGS_DESC=	webmail show flags patch
WEBMAILXFACE_DESC=	experimental webmail X-Face patch
SYSTEMALIASES_DESC=	symlink system /etc/aliases
EMPTYALIASES_DESC=	create empty aliases file
RCCONF_DESC=	modify rc.conf to enable courier/disable sendmail
MAILCONF_DESC=	modify mailer.conf to use courier instead of sendmail
PERIODIC_DESC=	modify/create periodic.conf

.include <bsd.port.options.mk>

.include "${.CURDIR}/Makefile.doc"
.include "${.CURDIR}/Makefile.own"

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
WITH_AUTH_LDAP=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/courier-authlib/libauthldap.so:net/courier-authlib-ldap
CONFIGURE_ARGS+=--with-ldapaliasd
PLIST_SUB+=	WITHLDAP=""
SUB_LIST+=	WITHLDAP=""
.else
CONFIGURE_ARGS+=--without-ldapaliasd
PLIST_SUB+=	WITHLDAP="@comment "
SUB_LIST+=	WITHLDAP="@comment "
.endif

.if ${PORT_OPTIONS:MSYSTEMALIASES}
PLIST_SUB+=	WITHSYSTEMALIASES=""
SUB_LIST+=	WITHSYSTEMALIASES=""
.else
PLIST_SUB+=	WITHSYSTEMALIASES="@comment "
SUB_LIST+=	WITHSYSTEMALIASES="@comment "
.endif

.if ${PORT_OPTIONS:MEMPTYALIASES}
PLIST_SUB+=	WITHEMPTYALIASES=""
SUB_LIST+=	WITHEMPTYALIASES=""
.else
PLIST_SUB+=	WITHEMPTYALIASES="@comment "
SUB_LIST+=	WITHEMPTYALIASES="@comment "
.endif

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

.if ${PORT_OPTIONS:MGNUPG}
BUILD_DEPENDS+=	gpg:security/gnupg
RUN_DEPENDS+=	gpg:security/gnupg
.endif

.if ${PORT_OPTIONS:MASPELL}
BUILD_DEPENDS+=	aspell:textproc/aspell
RUN_DEPENDS+=	aspell:textproc/aspell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/aspell
.elif ${PORT_OPTIONS:MISPELL}
BUILD_DEPENDS+=	ispell:textproc/aspell-ispell
RUN_DEPENDS+=	ispell:textproc/aspell-ispell
CONFIGURE_ARGS+=--with-ispell=${LOCALBASE}/bin/ispell
.else
CONFIGURE_ARGS+=--without-ispell
.endif

.if ${PORT_OPTIONS:MPROCMAIL}
BUILD_DEPENDS+=	procmail:mail/procmail
RUN_DEPENDS+=	procmail:mail/procmail
.endif

.if ${PORT_OPTIONS:MSENDFAX}
USES+=		ghostscript
SENDFAX_DEPENDS=sendfax:comms/mgetty+sendfax \
		pnmscale:graphics/netpbm
BUILD_DEPENDS+=	${SENDFAX_DEPENDS}
RUN_DEPENDS+=	${SENDFAX_DEPENDS}
WITH_TRANSPORT+=fax
PLIST_SUB+=	WITHFAX=""
SUB_LIST+=	WITHFAX=""
.else
PLIST_SUB+=	WITHFAX="@comment "
SUB_LIST+=	WITHFAX="@comment "
.endif

.if ${PORT_OPTIONS:MUUCP}
.if !exists(/usr/bin/uux)
BUILD_DEPENDS+=	uux:net/freebsd-uucp
RUN_DEPENDS+=	uux:net/freebsd-uucp
.endif
WITH_TRANSPORT+=uucp
PLIST_SUB+=	WITHUUCP=""
.else
PLIST_SUB+=	WITHUUCP="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--with-ipv6
.else
CONFIGURE_ARGS+=--without-ipv6
.endif

.if ${PORT_OPTIONS:MMAILDROPFLAGS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-maildrop__maildir.C
.endif

.if ${PORT_OPTIONS:MWEBMAILXFACE}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__msg2html.c
.endif

.if ${PORT_OPTIONS:MWEBMAILFLAGS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__folder.c ${FILESDIR}/extra-patch-webmail__maildir.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-webmail__maildir.h ${FILESDIR}/extra-patch-webmail__images__sqwebmail.css
.endif

.if ${PORT_OPTIONS:MWEBMAILRSENT}
CONFIGURE_ARGS+=--enable-autorenamesent
.else
CONFIGURE_ARGS+=--disable-autorenamesent
.endif

.if ${PORT_OPTIONS:MMAILCONF}
SUB_LIST+=	MAILCONF="y"
.else
SUB_LIST+=	MAILCONF="n"
.endif

.if ${PORT_OPTIONS:MRCCONF}
SUB_LIST+=	RCCONF="y"
.else
SUB_LIST+=	RCCONF="n"
.endif

.if ${PORT_OPTIONS:MPERIODIC}
SUB_LIST+=	PERIODIC="y"
.else
SUB_LIST+=	PERIODIC="n"
.endif

pre-everything::
	@${ECHO_MSG} "===> --------------------------------------------------------"
	@${ECHO_MSG} "===>	Run 'make config' to (re)configure ${PKGNAME}"
	@${ECHO_MSG} "===> --------------------------------------------------------"

pre-patch:
	@${CP} ${TEMPLATES}/config.guess ${TEMPLATES}/config.sub ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|^PROG=\./|PROG=exec ./|g' \
		${WRKSRC}/courier/module.*/courier.config
	@${REINPLACE_CMD} -e 's|@mydatadir@|@sysconfdir@|g' \
		${WRKSRC}/*/mk*cert.* \
		${WRKSRC}/*/*/mk*cert.*
	@${REINPLACE_CMD} -e 's|^\(TLS_CERTFILE=\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.dist.in \
		${WRKSRC}/*/*/*.dist.in
	@${REINPLACE_CMD} -e 's|^\(RANDFILE[[:space:]]*=[[:space:]]*\)@mydatadir@|\1@sysconfdir@|g' \
		${WRKSRC}/*/*.cnf.openssl.in \
		${WRKSRC}/*/*/*.cnf.openssl.in
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) \(.$$$$file.\)|${INSTALL_MAN} \1|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/*/Makefile.in \
		${WRKSRC}/*/*/Makefile.in \
		${WRKSRC}/*/*/*/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(INSTALL_STRIP_PROGRAM=\).*$$|\1"${INSTALL_PROGRAM} -s"|' \
			-e 's|; ldapaliasd="yes"||' \
		${WRKSRC}/configure \
		${WRKSRC}/*/configure \
		${WRKSRC}/*/*/configure \
		${WRKSRC}/*/*/*/configure
	@${REINPLACE_CMD} -E -e 's/(root|bin)[[:space:]]*bin/root	wheel/g' \
		${WRKSRC}/courier/perms.sh.in
	@${REINPLACE_CMD} '/^courieresmtp_LDADD =/s/$$/ -lcourierauth/' \
		${WRKSRC}/courier/module.esmtp/Makefile.in

post-build:
	@${PERL} -pi -e 's|^(auth)\s+(required).*|$$1\t\t$$2\tpam_unix.so\ttry_first_pass|g;' \
		     -e 's|^(account)\s+(required).*|$$1 \t$$2\tpam_unix.so|g;' \
		     -e 's|^(session)\s+(required).*|$$1 \t$$2\tpam_permit.so|g;' \
		${WRKSRC}/*/*.authpam* \
		${WRKSRC}/*/*/*.authpam*
	@${LN} -f ${WRKSRC}/gpglib/README.html		${WRKSRC}/gpglib/README.gpglib.html
	@${LN} -f ${WRKSRC}/imap/BUGS			${WRKSRC}/imap/BUGS.imap
	@${LN} -f ${WRKSRC}/imap/BUGS.html		${WRKSRC}/imap/BUGS.imap.html
	@${LN} -f ${WRKSRC}/imap/README			${WRKSRC}/imap/README.imap
	@${LN} -f ${WRKSRC}/imap/README.html		${WRKSRC}/imap/README.imap.html
	@${LN} -f ${WRKSRC}/maildrop/README.html	${WRKSRC}/maildrop/README.maildrop.html
	@${LN} -f ${WRKSRC}/pcp/README.html		${WRKSRC}/pcp/README.pcp.html
	@${LN} -f ${WRKSRC}/webmail/BUGS		${WRKSRC}/webmail/BUGS.webmail
	@${LN} -f ${WRKSRC}/webmail/BUGS.html		${WRKSRC}/webmail/BUGS.webmail.html
	@${LN} -f ${WRKSRC}/webmail/SECURITY		${WRKSRC}/webmail/SECURITY.webmail
	@${LN} -f ${WRKSRC}/webmail/SECURITY.html	${WRKSRC}/webmail/SECURITY.webmail.html

post-install:
	@${LN} -f ${STAGEDIR}${SYSCONFDIR}/maildrop ${STAGEDIR}${SYSCONFDIR}/maildropfilter
	@${INSTALL_DATA} /dev/null ${STAGEDIR}${SYSCONFDIR}/locallowercase
	@${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${SYSCONFDIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate ${STAGEDIR}${DATADIR}/
.for file in ${OWNER0}
	@-${CHOWN} -Rh ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}/${file}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${HTMLDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/html
.endfor
	@${INSTALL_DATA} ${STAGEDIR}${DATADIR}/htmldoc/* ${STAGEDIR}${DOCSDIR}/html
.endif
	@${RM} -rf ${STAGEDIR}${DATADIR}/htmldoc
	@-${CHOWN} -Rh ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}
	@${CHMOD} -R a+r ${STAGEDIR}${DATADIR}/courierwebadmin
	@${CHMOD} -R a-w ${STAGEDIR}${DATADIR} ${STAGEDIR}${LIBEXECDIR}/courier
	@${CHMOD} 550 ${STAGEDIR}${LIBEXECDIR}/courier/modules/esmtp/courieresmtp*

.include <bsd.port.mk>
