# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	courier-imap
PORTVERSION=	4.14
PORTEPOCH=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/courier/imap/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	IMAP (and POP3) server that provides access to Maildir mailboxes

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

USES=		gmake perl5
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	courier-imap-imapd courier-imap-imapd-ssl \
		courier-imap-pop3d courier-imap-pop3d-ssl

CPPFLAGS+=	-I${LOCALBASE}/include -I${PREFIX}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${PREFIX}/lib
CONFIGURE_ENV=	REHASH=${SCRIPTDIR}/c_rehash

MAKE_ENV:=	${CONFIGURE_ENV}

#
NO_STAGE=	yes
# options available:
#
# WITH_SYSLOG_FACILITY:         The syslogfacility to use
#

OPTIONS_DEFINE=	FAM TRASHQUOTA GDBM IPV6
FAM_DESC=	Fam support for IDLE command
TRASHQUOTA_DESC=	Include deleted mails in the quota

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

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

.if ${PORT_OPTIONS:MSYSLOG_FACILITY}
CONFIGURE_ARGS+=--with-syslog=${WITH_SYSLOG_FACILITY}
.endif

.if ${PORT_OPTIONS:MAUTH_USERDB}
.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=--with-db=gdbm --with-userdb=${USERDB}
LIB_DEPENDS+=	gdbm.4:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=--with-db=db  --with-userdb=${USERDB}
.endif
.endif

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--without-ipv6
.endif

.if ${PORT_OPTIONS:MTRASHQUOTA}
CONFIGURE_ARGS+=--with-trashquota
.endif

.if ${PORT_OPTIONS:MFAM}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_FAM=	yes
.endif

MAN1=		couriertcpd.1 maildiracl.1 maildirkw.1 \
		maildirmake.1

MAN8=		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

EXTRA_DOCS=	AUTHORS INSTALL NEWS \
		libs/imap/ChangeLog \
		libs/imap/README \
		libs/imap/README.proxy \
		libs/maildir/README.imapkeywords.html \
		libs/maildir/README.maildirfilter.html \
		libs/maildir/README.maildirquota.txt \
		libs/maildir/README.sharedfolders.txt \
		libs/tcpd/README.couriertls \

post-patch:
.if ! ${PORT_OPTIONS:MFAM}
	@${REINPLACE_CMD} -e 's|$$LIBFAM||g; s|HAVE_FAM|DO_NOT_HAVE_FAM|g' \
		${WRKSRC}/libs/maildir/configure
.endif
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/libs/liblock/configure
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/libs/imap/Makefile.in
	@${REINPLACE_CMD} -e 's|TLS_PROTOCOL=SSL3|TLS_PROTOCOL=SSL23|g' \
		${WRKSRC}/libs/imap/pop3d-ssl.dist.in \
		${WRKSRC}/libs/imap/imapd-ssl.dist.in

post-install:
.for i in imapd pop3d
	${INSTALL_DATA} ${WRKSRC}/libs/imap/${i}.cnf ${CONFDIR}/${i}.cnf.dist
.endfor
.if ${PORT_OPTIONS:MDOCS}
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
