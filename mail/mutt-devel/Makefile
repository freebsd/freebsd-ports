# ex:ts=8
# Ports collection makefile for:  mutt development
# Date created:			  6 Jun 2001
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#
# There are several knobs which are used to define additions to the core
# mutt functionality.
#
# As all of the knobs have a unique name which should not interfere with
# other ports you can add them to /etc/make.conf, e.g. a line like
# "WITH_MUTT_HTML=yes" will enable mutt's HTML documentation.
#
# In addition to the knobs listed below you can enable other configuration
# options of mutt by adding them to the MUTT_CONFIGURE_ARGS variable. For
# example you could say "MUTT_CONFIGURE_ARGS=--with-homespool=MyMail" to
# configure a different file for mutt's homespool.
#
# The two most important knobs are:
#
# In general you can choose between using the SLANG port (WITH_MUTT_SLANG)
# and ncurses (WITH_MUTT_NCURSES) which is the default. Note that you may
# have to set the variables COLORTERM=yes and COLORFGBG=color,color in your
# environment to get slang function properly.
#
# If you want to install the mutt documentation in html and ps format define:
#  WITH_MUTT_HTML
#
# If you do not want that the documentation is rebuilt using sgmlformat
# define:
#  WITHOUT_MUTT_SGMLFORMAT
#    (this can't be stated if WITH_MUTT_HTML is defined)
#
# If you want to read and post news with mutt define:
#  WITH_MUTT_NNTP
#
# WITH_MUTT_SSL can be enabled if your IMAP/POP server is SSL capable.
#
# If you want to use the SASL authentication features with your email server
# define
#  WITH_MUTT_CYRUS_SASL
#
# If you want to access compressed email folders define:
#  WITH_MUTT_COMPRESSED_FOLDERS
#
# If you want to enable extended quoting functions define:
#  WITH_MUTT_QUOTE_PATCH
#
# If you want to disable a outlook_compat function for use with smime define:
#  WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT
#
# If you want to use the rethreading functions define:
#  WITH_MUTT_EDIT_THREADS
#
# If you want to use the signature menu define:
#  WITH_MUTT_SIGNATURE_MENU
#
# If you want to use enhanced pgp features define:
#  WITH_MUTT_PGP_PATCH
#
# If you want to use the printf-like enhancement to the mbox-hook command
# define:
#  WITH_MUTT_MBOX_HOOK_PATCH
#
# If you want to use the ifdef feature define:
#  WITH_MUTT_IFDEF_PATCH

PORTNAME=	mutt-devel
PORTVERSION=	1.5.3
#PORTREVISION?=	0
CATEGORIES+=	mail
.if defined(WITH_MUTT_NNTP)
CATEGORIES+=	news
.endif
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/ \
		ftp://ftp.mutt.org/mutt/devel/
DISTNAME=	mutt-${PORTVERSION}i

MAINTAINER=	udo.schweigert@siemens.com

DIST_SUBDIR=    mutt
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-flock --disable-fcntl \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--sysconfdir=${PREFIX}/etc --enable-external-dotlock \
		--with-libiconv-prefix=${PREFIX} --enable-pop --enable-imap
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

USE_REINPLACE=	yes
USE_AUTOMAKE=	yes

PLIST=		${WRKDIR}/PLIST
SCRIPTS_ENV=	WRKDIR="${WRKDIR}"

.include <bsd.port.pre.mk>

.if defined(WITH_MUTT_COMPRESSED_FOLDERS) || defined(WITH_MUTT_NNTP) || \
		defined(WITH_MUTT_QUOTE_PATCH)
PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		http://www2.mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${PATCH_VERSION}/ \
		ftp://ftp2.mutt.org.ua/pub/mutt/mutt-${PATCH_VERSION}/
.endif

.if defined(WITH_MUTT_EDIT_THREADS) || defined(WITH_MUTT_SIGNATURE_MENU) || \
		defined(WITH_MUTT_IFDEF_PATCH)
PATCH_SITES+=	http://cedricduval.free.fr/download/mutt/
.endif
.if defined(WITH_MUTT_MBOX_HOOK_PATCH) 
PATCH_SITES+=	http://home.woolridge.ca/mutt/patches/
.endif

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	${REINPLACE_CMD} -E -e "s|^(ACLOCAL = ).+|\1${ACLOCAL}|" \
			-e "s|^(AUTOCONF = ).+|\1${AUTOCONF}|" \
			-e "s|^(AUTOMAKE = ).+|\1${AUTOMAKE}|" \
			-e "s|^(AUTOHEADER = ).+|\1${AUTOHEADER}|" \
		${BUILD_WRKSRC}/Makefile

.if !defined(PATCH_VERSION)
PATCH_VERSION=	${PORTVERSION}
.endif

.if defined(PACKAGE_BUILDING)
WITH_MUTT_SSL=		yes
WITH_MUTT_NCURSES=	yes
WITH_MUTT_HTML=		yes
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.endif

.if defined(WITH_MUTT_PS)
WITH_MUTT_HTML=		yes
.endif
.if defined(WITH_MUTT_NCURSES_PORT)
WITH_MUTT_NCURSES=	yes
.endif
.if defined(WITH_MUTT_NCURSES)
USE_NCURSES=	yes
.endif
.if defined(WITH_MUTT_SLANG) && !defined(USE_NCURSES)
USE_SLANG=	yes
.endif
.if !defined(USE_NCURSES) && !defined(WITHOUT_MUTT_NCURSES) && !defined(USE_SLANG)
USE_NCURSES=	yes
.endif
.if defined(WITHOUT_MUTT_SGMLFORMAT)
SGML_USED=	no
.endif
.if !defined(SGML_USED)
SGML_USED=	no
.endif

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

.if defined(NOPORTDOCS)
SGML_USED=	no
.endif
.if defined(USE_NCURSES) && ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.elif defined(USE_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif
.if defined(WITH_MUTT_SSL)
USE_OPENSSL=	yes
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(WITH_MUTT_PGP_PATCH)
.error The WITH_MUTT_PGP_PATCH option is currently not available
#SGML_NEEDED=	yes
#pre-configure::
#	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-pgp-dw
.endif
.if defined(WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT)
pre-configure::
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-smime-no-outlook
.endif

.if defined(WITH_MUTT_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(USE_NCURSES) && ${OSVERSION} < 400000
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.elif defined(USE_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.endif
.if defined(WITH_MUTT_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

PATCH_DIST_STRIP=	-p1

.if defined(WITH_MUTT_COMPRESSED_FOLDERS)
PATCHFILES+=	patch-${PATCH_VERSION}.rr.compressed.gz
CONFIGURE_ARGS+=	--enable-compressed
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_NNTP)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.nntp.gz
CONFIGURE_ARGS+=	--enable-nntp
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_QUOTE_PATCH)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.initials.gz \
		patch-${PATCH_VERSION}.vvv.quote.gz
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_EDIT_THREADS)
.error The WITH_MUTT_EDIT_THREADS option is currently not available
#PATCHFILES+=	patch-${PATCH_VERSION}.cd.edit_threads.9.2
CONFIGURE_ARGS+=	--enable-imap-edit-threads
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
.error The WITH_MUTT_SIGNATURE_MENU option is currently not available
#PATCHFILES+=	patch-${PATCH_VERSION}.cd.signatures_menu.2.1
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
.error The WITH_MUTT_IFDEF_PATCH option is currently not available
#PATCHFILES+=	patch-${PATCH_VERSION}.cd.ifdef.1
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_MBOX_HOOK_PATCH)
.error The WITH_MUTT_MBOX_HOOK_PATCH option is currently not available
#PATCHFILES+=	patch-${PATCH_VERSION}.dw.mbox-hook.1
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		muttrc.5 mbox.5

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${CP} ${PATCHDIR}/smime.h ${WRKSRC}

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)

.if defined(WITH_MUTT_NNTP)
SCRIPTS_ENV+=	MUTT_NNTP="yes"
.endif
.if defined(WITH_MUTT_COMPRESSED_FOLDERS)
SCRIPTS_ENV+=	MUTT_COMPRESSED_FOLDERS="yes"
.endif
.if defined(WITH_MUTT_QUOTE_PATCH)
SCRIPTS_ENV+=	MUTT_QUOTE_PATCH="yes"
.endif
.if defined(WITH_MUTT_EDIT_THREADS)
SCRIPTS_ENV+=	MUTT_EDIT_THREADS="yes"
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
SCRIPTS_ENV+=	MUTT_SIGNATURE_MENU="yes"
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
SCRIPTS_ENV+=	MUTT_IFDEF_PATCH="yes"
.endif
.if defined(WITH_MUTT_PGP_PATCH)
SCRIPTS_ENV+=	MUTT_PGP_PATCH="yes"
.endif
.if defined(WITH_MUTT_HTML)
SCRIPTS_ENV+=	MUTT_HTML="yes"
.endif

.if !defined(NOPORTDOCS)
SCRIPTS_ENV+=	MUTT_PORTDOCS="yes"
post-build:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(WITH_MUTT_HTML)
SGML_USED=	yes
.endif
.if defined(SGML_NEEDED) && !defined(WITHOUT_MUTT_SGMLFORMAT)
SGML_USED=	yes
.endif
.else 	# ! NOPORTDOCS
post-patch::
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif # ! NOPORTDOCS

.if ${SGML_USED} == yes
SCRIPTS_ENV+=	MUTT_SGML="yes"
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
post-patch::
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-sgmlformat
.endif

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/generate-plist > ${PLIST}

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt \
		PGP-Notes.txt ../ABOUT-NLS ../contrib/language* \
		${PREFIX}/share/doc/mutt
.if ${SGML_USED} == yes
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.latin1 manual.ps \
		${PREFIX}/share/doc/mutt
.endif
.if defined(WITH_MUTT_NNTP)
	@cd ${WRKSRC} ; ${INSTALL_MAN} ChangeLog.nntp \
		${PREFIX}/share/doc/mutt
.endif
.if defined(WITH_MUTT_HTML)
	@${MKDIR} ${PREFIX}/share/doc/mutt/html && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
.endif
.endif

.include <bsd.port.post.mk>
