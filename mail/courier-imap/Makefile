# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	3.0.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

.if defined(WITH_DRAC)
PATCH_SITES=	http://www.smalltown.ne.jp/~usata/pub/patch/
PATCHFILES=	courier-imap-3.0.6-drac.patch
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	IMAP (and POP3) server that provides access to Maildir mailboxes

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LDFLAGS} -L${LOCALBASE}/lib"

#
# options available:
#
# WITHOUT_OPENSSL:		Don't build in TLS support
# WITHOUT_PAM:			Don't build in PAM support
# WITHOUT_AUTHDAEMON		Don't build the authdaemon
# WITH_CRAM:			Build in CRAM-MD5 authentication support
# WITH_VPOPMAIL:		Build in vpopmail support
# WITH_MYSQL:			Build in mysql support
# WITH_POSTGRESQL:		Build in postgresql support
# WITH_LDAP:			Build in ldap support with openldap
# WITH_FAM:			Build in fam support for IDLE command
# WITH_DRAC:			Build in DRAC support
# WITH_TRASHQUOTA:		Include deleted mails in the quota
# WITH_GDBM:			Use gdbm files instead of bdb
#

CONFDIR?=	${PREFIX}/etc/${PORTNAME}
RCDIR?=		${PREFIX}/etc/rc.d
USERDB?=	${PREFIX}/etc/userdb
LIBEXECDIR?=	${PREFIX}/libexec/${PORTNAME}

VPOPMAILDIR?=	${LOCALBASE}/vpopmail

PLIST_SUB=	CONFDIR=${CONFDIR:S,^${PREFIX}/,,} \
		RCDIR=${RCDIR:S,^${PREFIX}/,,} \
		USERDB=${USERDB:S,^${PREFIX}/,,} \
		LIBEXECDIR=${LIBEXECDIR:S,^${PREFIX}/,,}

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	YES
PLIST_SUB+=	OPENSSLFLAG=
.else
PLIST_SUB+=	OPENSSLFLAG="@comment "
.endif

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-authshadow \
		--sysconfdir=${CONFDIR} \
		--with-userdb=${USERDB} \
		--datadir=${DATADIR} \
		--libexecdir=${LIBEXECDIR} \
		--enable-workarounds-for-imap-client-bugs \
		--enable-unicode \
		--disable-root-check \
		--with-locking-method=fcntl

# Without explicitly mentioning this, if gdbm libraries are present,
# they are silently picked up and used by courier-imap in place of
# the standard db (v1) files.
#
.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-db=gdbm
.else
CONFIGURE_ARGS+=	--with-db=db
.endif

.if !defined(WITH_VPOPMAIL)
CONFIGURE_ARGS+=--without-authvchkpw
PLIST_SUB+=	VPOPMAILFLAG="@comment "
.else
CONFIGURE_ARGS+=--with-authvchkpw
BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
PLIST_SUB+=	VPOPMAILFLAG=""
.endif

.if defined(WITH_TRASHQUOTA)
CONFIGURE_ARGS+=--with-trashquota
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-authldap
PLIST_SUB+=	LDAPFLAG=""
.else
CONFIGURE_ARGS+=--without-authldap
PLIST_SUB+=	LDAPFLAG="@comment "
.endif

.if !defined(WITH_MYSQL)
CONFIGURE_ARGS+=--without-authmysql
PLIST_SUB+=	MYSQLFLAG="@comment "
.else
USE_MYSQL=	YES
PLIST_SUB+=	MYSQLFLAG=""
CONFIGURE_ARGS+=--with-authmysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql
.endif

.if !defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=--without-authpgsql
PLIST_SUB+=	PGSQLFLAG="@comment "
.else
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
PLIST_SUB+=	PGSQLFLAG=""
.endif

.if !defined(WITHOUT_AUTHDAEMON)
CONFIGURE_ARGS+=--with-authdaemon
PLIST_SUB+=	AUTHDFLAG=""
.else
CONFIGURE_ARGS+=--without-authdaemon
PLIST_SUB+=	AUTHDFLAG="@comment "
.endif

.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=--with-authpam
PLIST_SUB+=	PAMFLAG="" PWDFLAG="@comment "
.else
CONFIGURE_ARGS+=--without-authpam
PLIST_SUB+=	PAMFLAG="@comment " PWDFLAG=""
.endif

.if !defined(WITH_CRAM)
CONFIGURE_ARGS+=--without-authcram
.else
CONFIGURE_ARGS+=--with-authcram
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FAM) || exists(${LOCALBASE}/lib/libfam.so)
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

.if defined(WITH_DRAC)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-drac
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

MAN1=		courierlogger.1 couriertcpd.1 maildiracl.1 maildirkw.1 \
		maildirmake.1
MAN7=		authlib.7
MAN8=		makeuserdb.8 userdb.8 userdbpw.8 \
		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

MLINKS=		authlib.7 authpwd.7 \
		authlib.7 authuserdb.7 \
		authlib.7 authshadow.7 \
		authlib.7 authpam.7 \
		authlib.7 authvchkpw.7 \
		authlib.7 authcram.7 \
		authlib.7 authldap.7 \
		authlib.7 authmysql.7 \
		authlib.7 authdaemon.7 \
		authlib.7 authdaemond.7 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

EXTRA_DOCS=	README INSTALL AUTHORS imap/ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/liblock/configure
	@${REINPLACE_CMD} -e 's|$$VPOPMAILLIBS|& -lcrypt|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/authlib/configure
	@${REINPLACE_CMD} -e 's|^@INSTALLAUTHMODULES@$$|& @AUTHMODULES@|' \
		${WRKSRC}/authlib/installlist.in
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/authlib/Makefile.in

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authtest ${PREFIX}/bin/
.for i in imapd pop3d
	${INSTALL_DATA} ${WRKSRC}/imap/${i}.cnf ${CONFDIR}/${i}.cnf.dist
	${LN} -s ${LIBEXECDIR}/${i}.rc ${RCDIR}/${PORTNAME}-${i}.sh.sample
	${LN} -s ${LIBEXECDIR}/${i}-ssl.rc ${RCDIR}/${PORTNAME}-${i}-ssl.sh.sample
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You will have to run ${DATADIR}/mkimapdcert to create"
	@${ECHO_MSG} "a self-signed certificate if you want to use imapd-ssl."
	@${ECHO_MSG} "And you will have to copy and edit the *.dist files to *"
	@${ECHO_MSG} "in ${CONFDIR}."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "In case you use authpam, you should put the following lines"
	@${ECHO_MSG} "in your /etc/pam.conf or /etc/pam.d/imap"
	@${ECHO_MSG} "imap    auth    required    pam_unix.so         try_first_pass"
	@${ECHO_MSG} "imap    account required    pam_unix.so         try_first_pass"
	@${ECHO_MSG} "imap    session required    pam_permit.so"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "In case you are upgrading an existing Installation, you need to run"
	@${ECHO_MSG} "'make install-configure' to update your old configuration files."
	@${ECHO_MSG} ""

install-configure:
	cd ${WRKSRC} && ${GMAKE} install-configure

.include <bsd.port.post.mk>
