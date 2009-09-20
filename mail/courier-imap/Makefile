# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	4.6.0
PORTEPOCH=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/courier/imap/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	IMAP (and POP3) server that provides access to Maildir mailboxes

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	courier-imap-imapd courier-imap-imapd-ssl \
		courier-imap-pop3d courier-imap-pop3d-ssl


CPPFLAGS+=	-I${LOCALBASE}/include -I${PREFIX}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${PREFIX}/lib
CONFIGURE_ENV=	REHASH=${SCRIPTDIR}/c_rehash \
		CPPFLAGS='${CPPFLAGS}' \
		CXXFLAGS='${CPPFLAGS}' \
		LDFLAGS='${LDFLAGS}'
MAKE_ENV:=	${CONFIGURE_ENV}

#
# options available:
#
# WITH_SYSLOG_FACILITY:         The syslogfacility to use
#

OPTIONS=	FAM		"Build in fam support for IDLE command"		off \
		TRASHQUOTA	"Include deleted mails in the quota"		off \
		GDBM		"Use gdbm db instead of system bdb"		off \
		IPV6		"Build with IPv6 support"			on

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.opt)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"
.endif

CONFDIR?=	${PREFIX}/etc/${PORTNAME}
USERDB?=	${PREFIX}/etc/userdb
LIBEXECDIR?=	${PREFIX}/libexec/${PORTNAME}
USE_OPENSSL=	yes
PLIST_SUB=	CONFDIR=${CONFDIR:S,^${PREFIX}/,,} \
		LIBEXECDIR=${LIBEXECDIR:S,^${PREFIX}/,,}

CONFIGURE_ARGS=	--sysconfdir=${CONFDIR} \
		--datadir=${DATADIR} \
		--libexecdir=${LIBEXECDIR} \
		--enable-workarounds-for-imap-client-bugs \
		--enable-unicode \
		--disable-root-check \
		--with-locking-method=fcntl \
		COURIERAUTHCONFIG=${PREFIX}/bin/courierauthconfig

.include <bsd.port.pre.mk>

#does not work with 4.4.0
#.if defined(WITH_DRAC)
# move me below .include <bsd.port.pre.mk> when re-enabling
#PATCH_SITES=	http://www.smalltown.ne.jp/~usata/pub/patch/
#PATCHFILES=	courier-imap-4.1.0-drac.patch
#BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
#.endif

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

.if defined(WITH_SYSLOG_FACILITY)
CONFIGURE_ARGS+=--with-syslog=${WITH_SYSLOG_FACILITY}
.endif

.if defined(WITH_AUTH_USERDB)
.if defined(WITH_GDBM)
CONFIGURE_ARGS+=--with-db=gdbm --with-userdb=${USERDB}
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=--with-db=db  --with-userdb=${USERDB}
.endif
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--without-ipv6
.endif

.if defined(WITH_TRASHQUOTA)
CONFIGURE_ARGS+=--with-trashquota
.endif

.if defined(WITH_FAM)
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

MAN1=		couriertcpd.1 maildiracl.1 maildirkw.1 \
		maildirmake.1

MAN8=		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

EXTRA_DOCS=	AUTHORS INSTALL NEWS imap/ChangeLog imap/README \
		imap/README.proxy maildir/README.imapkeywords.html \
		maildir/README.maildirfilter.html \
		maildir/README.maildirquota.txt \
		maildir/README.sharedfolders.txt tcpd/README.couriertls \

post-patch:
.if !defined(WITH_FAM)
	@${REINPLACE_CMD} -e 's|$$LIBFAM||g; s|HAVE_FAM|DO_NOT_HAVE_FAM|g' \
		${WRKSRC}/maildir/configure
.endif
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/liblock/configure
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/imap/Makefile.in
	@${REINPLACE_CMD} -e 's|TLS_PROTOCOL=SSL3|TLS_PROTOCOL=SSL23|g' \
		${WRKSRC}/imap/pop3d-ssl.dist.in \
		${WRKSRC}/imap/imapd-ssl.dist.in

post-install:
.for i in imapd pop3d
	${INSTALL_DATA} ${WRKSRC}/imap/${i}.cnf ${CONFDIR}/${i}.cnf.dist
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

	cd ${WRKSRC} && ( ${GMAKE} install-configure ; cd - )

	@${ECHO_MSG} "In case you use authpam, you should put the following lines"
	@${ECHO_MSG} "in your /etc/pam.d/imap"
	@${ECHO_MSG} "auth    required    pam_unix.so         try_first_pass"
	@${ECHO_MSG} "account required    pam_unix.so         try_first_pass"
	@${ECHO_MSG} "session required    pam_permit.so"

	@${ECHO_MSG} ""
	@${ECHO_MSG} "You will have to run ${DATADIR}/mkimapdcert to create"
	@${ECHO_MSG} "a self-signed certificate if you want to use imapd-ssl."
	@${ECHO_MSG} "And you will have to copy and edit the *.dist files to *"
	@${ECHO_MSG} "in ${CONFDIR}."
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
