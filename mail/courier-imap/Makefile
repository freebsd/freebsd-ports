# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	4.0.1
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

BUILD_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib
RUN_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib

.if defined(WITH_DRAC)
BROKEN=		DRAC support doesn't work with 4.0.0 right now
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
USE_RC_SUBR=	yes

CONFIGURE_ENV=	CFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LDFLAGS} -L${LOCALBASE}/lib"

#
# options available:
#
# WITHOUT_OPENSSL:		Don't build in TLS support
# WITH_FAM:			Build in fam support for IDLE command
# WITH_DRAC:			Build in DRAC support
# WITH_TRASHQUOTA:		Include deleted mails in the quota
# WITH_GDBM:			Use gdbm files instead of bdb
#

CONFDIR?=	${PREFIX}/etc/${PORTNAME}
RCDIR?=		${PREFIX}/etc/rc.d
USERDB?=	${PREFIX}/etc/userdb
LIBEXECDIR?=	${PREFIX}/libexec/${PORTNAME}

PLIST_SUB=	CONFDIR=${CONFDIR:S,^${PREFIX}/,,} \
		RCDIR=${RCDIR:S,^${PREFIX}/,,} \
		USERDB=${USERDB:S,^${PREFIX}/,,} \
		LIBEXECDIR=${LIBEXECDIR:S,^${PREFIX}/,,}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--sysconfdir=${CONFDIR} \
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

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	YES
PLIST_SUB+=	OPENSSLFLAG=
.else
PLIST_SUB+=	OPENSSLFLAG="@comment "
.endif

.if defined(WITH_TRASHQUOTA)
CONFIGURE_ARGS+=--with-trashquota
.endif

RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

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

MAN1=		couriertcpd.1 maildiracl.1 maildirkw.1 \
		maildirmake.1

MAN8=		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

EXTRA_DOCS=	AUTHORS INSTALL NEWS imap/ChangeLog imap/README \
		imap/README.proxy maildir/README.imapkeywords.html \
		maildir/README.maildirfilter.html \
		maildir/README.maildirquota.txt \
		maildir/README.sharedfolders.txt tcpd/README.couriertls \


post-patch:
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/liblock/configure
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/imap/Makefile.in

post-install:
.for i in imapd pop3d
	${INSTALL_DATA} ${WRKSRC}/imap/${i}.cnf ${CONFDIR}/${i}.cnf.dist
.endfor
.for i in imapd imapd-ssl pop3d pop3d-ssl
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/courier-imap-${i}.sh > ${WRKDIR}/courier-imap-${i}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/courier-imap-${i}.sh ${RCDIR}/courier-imap-${i}.sh
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

	cd ${WRKSRC} && ( ${GMAKE} install-configure ; cd - )

	@${ECHO_MSG} ""
	@${ECHO_MSG} "You will have to run ${DATADIR}/mkimapdcert to create"
	@${ECHO_MSG} "a self-signed certificate if you want to use imapd-ssl."
	@${ECHO_MSG} "And you will have to copy and edit the *.dist files to *"
	@${ECHO_MSG} "in ${CONFDIR}."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
