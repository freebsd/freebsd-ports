# New ports collection makefile for:	mutt-ng
# Date created:		14 Jun 2005
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	mutt-ng
PORTVERSION=	20060501
CATEGORIES=	mail
MASTER_SITES=	http://nion.modprobe.de/mutt-ng/snapshots/		\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
DISTNAME=	muttng-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	A fork of the mutt with the goal to incorporate all the patches

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-fcntl --sysconfdir=${PREFIX}/etc \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${DOCSDIR} --with-charmaps
MAKE_ENV=	"EXAMPLESDIR=${EXAMPLESDIR}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB+=	NLS=""
.if defined(WITHOUT_MUTT_ICONV)
BROKEN=	The WITHOUT_MUTT_ICONV knob of the mutt port only works if WITHOUT_NLS is also given
.endif
.elif !defined(WITHOUT_MUTT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-iconv
.endif

OPTIONS=	POP "Enable pop3 support" on \
		IMAP "Enable imap support" on \
		NNTP "Enable nntp support" off \
		COMPRESSED "Enable compressed folder support" on \
		FLOCK "Enable flock to lock files" on \
		HCACHE_DB4 "Enable headers caching via DB4" on \
		HCACHE_GDBM "Enable headers caching via gdbm" off \
		HCACHE_QDBM "Enable headers caching via qdbm" off \
		ESMTP "Enable libesmtp support for sending mail" off \
		SLANG "Compile with SLANG frontend" off \
		NCURSES_PORT "Compile with ncurses frontend via port" off \
		SASL2 "Compile with sasl2 support for authentication" off \
		GNUTLS "Compile with SSL support via GNUTLS" off \
		LIBIDN "Enable international domain names" off \
		DEBUG "Compile a debug version" on

.include <bsd.port.pre.mk>

.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
WITH_MUTT_IMAP_HEADER_CACHE=	yes
.endif

.if defined (WITH_POP)
CONFIGURE_ARGS+=	--enable-pop
.endif

.if defined (WITH_IMAP) || defined(WITH_MUTT_IMAP_HEADER_CACHE)
CONFIGURE_ARGS+=	--enable-imap
.endif

.if defined(WITH_POP) || defined(WITH_IMAP) || defined(WITH_NNTP) || defined(WITH_SSL)
.if !defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-gnutls=${LOCALBASE}
LIB_DEPENDS+=		gnutls.15:${PORTSDIR}/security/gnutls
.endif
.endif

.if defined (WITH_NNTP) || defined(WITH_MUTT_NNTP)
CONFIGURE_ARGS+=	--enable-nntp
.endif

.if defined (WITH_COMPRESSED) || defined(WITH_MUTT_COMPRESSED_FOLDERS)
CONFIGURE_ARGS+=	--enable-compressed
.endif

.if defined (WITH_HCACHE_DB4) || defined(WITH_MUTT_IMAP_HEADER_CACHE)
CONFIGURE_ARGS+=	--enable-hcache --without-qdbm --without-gdbm --with-bdb=${LOCALBASE}
LIB_DEPENDS+=		db41.1:${PORTSDIR}/databases/db41
.elif defined (WITH_HCACHE_GDBM)
CONFIGURE_ARGS+=	--enable-hcache --without-qdbm
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
.elif defined (WITH_HCACHE_QDBM)
CONFIGURE_ARGS+=	--enable-hcache
LIB_DEPENDS+=		qdbm.12:${PORTSDIR}/databases/qdbm
.endif

.if defined (WITH_FLOCK)
CONFIGURE_ARGS+=	--enable-flock
CONFIGURE_ARGS+=	--disable-fcntl
.elif defined(WITHOUT_MUTT_FLOCK)
CONFIGURE_ARGS+=	--disable-flock
CONFIGURE_ARGS+=	--enable-fcntl
.endif

.if defined(WITH_SLANG) && !defined(WITH_NCURSES_PORT)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
CONFIGURE_ARGS+=	--with-slang=${LOCALBASE}
.elif defined(WITH_NCURSES_PORT) && !defined(WITH_SLANG)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CONFIGURE_ARGS+=	--with-curses=${LOCALBASE}
.elif defined(WITH_SLANG) && defined(WITH_NCURSES_PORT)
BROKEN=	You may not specify both WITH_SLANG and WITH_NCURSES options
.endif

.if defined(WITH_SASL2) || defined(WITH_MUTT_CYRUS_SASL2)
.if !defined(WITH_POP) && !defined(WITH_IMAP)
BROKEN=	SASL2 only is useful for imap or pop
.endif
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl2=${LOCALBASE}
.endif

.if defined(WITH_ESMTP)
LIB_DEPENDS+=	esmtp.6:${PORTSDIR}/mail/libesmtp
CONFIGURE_ARGS+=	--with-libesmtp=${LOCALBASE}
.endif

.if defined(WITH_LIBIDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-idn=${LOCALBASE}
.endif

.if defined (WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined (NOPORTDOCS)
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc
.endif

MAN1=	muttng.1 muttngbug.1 muttng_dotlock.1 fleang.1 muttng-flea.1
MAN5=	muttng-mbox.5 muttngrc.5

.if !defined(NOPORTDOCS)
post-build:
	@${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/mutt.man
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/muttrc.man
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Muttngrc ${PREFIX}/etc/Muttngrc.dist
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
