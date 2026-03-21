PORTNAME=	courier-imap
PORTVERSION=	5.3.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	mail
MASTER_SITES=	SF/courier/imap/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	IMAP (and POP3) server that provides access to Maildir mailboxes
WWW=		https://www.courier-mta.org/imap/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcourier-unicode.so:devel/courier-unicode \
		libcourierauth.so:security/courier-authlib-base \
		libidn2.so:dns/libidn2 \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool

USES=		compiler:c++11-lang gmake localbase:ldflags perl5 pkgconfig ssl \
		tar:bzip2
USE_RC_SUBR=	courier-imap-imapd courier-imap-imapd-ssl \
		courier-imap-pop3d courier-imap-pop3d-ssl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--disable-root-check \
		--enable-unicode \
		--enable-workarounds-for-imap-client-bugs \
		--libexecdir=${LIBEXECDIR} \
		--localstatedir="${PREFIX}/var" \
		--sysconfdir=${CONFDIR} \
		--with-locking-method=fcntl \
		--with-notice=unicode
CONFIGURE_ENV=	REHASH=${SCRIPTDIR}/c_rehash

MAKE_ENV:=	${CONFIGURE_ENV}
ALL_TARGET=	all makeimapaccess makedat

CONFLICTS=	courier imap-uw panda-imap

SUB_FILES=	pkg-message
SUB_LIST=	CONFDIR=${CONFDIR}

PLIST_SUB=	CONFDIR=${CONFDIR:S,^${PREFIX}/,,} \
		LIBEXECDIR=${LIBEXECDIR:S,^${PREFIX}/,,}

OPTIONS_DEFINE=	GDBM GNUTLS INOTIFY IPV6 TRASHQUOTA

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL (Enables SNI)
INOTIFY_DESC=		Inotify support for IDLE command
TRASHQUOTA_DESC=	Include deleted mails in the quota

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.opt)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"
.endif

CONFDIR?=	${PREFIX}/etc/${PORTNAME}
USERDB?=	${PREFIX}/etc/userdb
LIBEXECDIR?=	${PREFIX}/libexec/${PORTNAME}

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

IPV6_CONFIGURE_OFF=	--without-ipv6

TRASHQUOTA_CONFIGURE_ON=	--with-trashquota

EXTRA_DOCS=	AUTHORS INSTALL NEWS \
		libs/imap/ChangeLog \
		libs/imap/README.proxy \
		libs/maildir/README.imapkeywords.html \
		libs/maildir/README.maildirfilter.html \
		libs/maildir/README.maildirquota.txt \
		libs/maildir/README.sharedfolders.txt \
		libs/tcpd/README.couriertls

.include <bsd.port.options.mk>

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

#
# Variable avilable for further customization:
#
# WITH_SYSLOG_FACILITY:         The syslogfacility to use
#
.ifdef WITH_SYSLOG_FACILITY
CONFIGURE_ARGS+=	--with-syslog=${WITH_SYSLOG_FACILITY}
.endif

.if ${PORT_OPTIONS:MAUTH_USERDB}
.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=	--with-db=gdbm \
			--with-userdb=${USERDB}
LIB_DEPENDS+=		libgdbm.so:databases/gdbm
.else
CONFIGURE_ARGS+=	--with-db=db \
			--with-userdb=${USERDB}
.endif
.endif

.if ${PORT_OPTIONS:MINOTIFY} && ${OSVERSION} < 1500500
LIB_DEPENDS+=	libinotify.so:devel/libinotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/libs/liblock/configure
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		-e 's|@LN_S@|${RLN}|' \
		${WRKSRC}/Makefile.in

post-patch-INOTIFY-on:
.if ${OSVERSION} < 1500500
	@${REINPLACE_CMD} -e 's|LIBS = @LIBS@|& -L${LOCALBASE}/lib -linotify -lpthread|' \
		${WRKSRC}/libs/maildir/Makefile.in \
		${WRKSRC}/libs/imap/Makefile.in
.endif

post-configure-INOTIFY-on:
	@${ECHO_CMD} '#define HAVE_INOTIFY_INIT 1' >>${WRKSRC}/libs/maildir/config.h
	@${ECHO_CMD} '#define HAVE_INOTIFY_INIT1 1' >>${WRKSRC}/libs/maildir/config.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeimapaccess ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/makedat ${STAGEDIR}${PREFIX}/bin/
.for i in imapd pop3d
	${INSTALL_DATA} ${WRKSRC}/libs/imap/${i}.cnf ${STAGEDIR}${CONFDIR}/${i}.cnf.dist
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
