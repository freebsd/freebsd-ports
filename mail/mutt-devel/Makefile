# ex:ts=8
# Ports collection makefile for:  mutt development
# Date created:			  6 Jun 2001
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#

# There are several knobs which are used to define additions to the core
# mutt functionality. The two most important are:
#
#  WITH_MUTT_IMAP, which should be defined if you are accessing an IMAP server
#    (here you also can say WITH_MUTT_SSL, if your IMAP server is SSL capable)
#  WITH_MUTT_POP, which should be defined if you are accessing a POP server 
#    (here you also can say WITH_MUTT_SSL, if your POP server is SSL capable)
#
# In general you can choose between using the SLANG port (which is really 
# recommended and is now the default) and ncurses (WITH_MUTT_NCURSES). If you
# don't want to use SLANG define WITHOUT_MUTT_SLANG.
# 
# If you want to install the mutt documentation in html format define:
#  WITH_MUTT_HTML
#
# If you want to read news with mutt define:
#  WITH_MUTT_NNTP
#    (note that this implies building of the inn-stable port to be able to 
#     post new articles)
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
# If you want to enable extended functions for the ru locale define:
#  WITH_MUTT_RU_PATCH
 

PORTNAME=	mutt-devel
PORTVERSION=	1.3.25
PORTREVISION=	2
CATEGORIES+=	mail
.if defined(WITH_MUTT_NNTP)
CATEGORIES+=	news
.endif
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/mirrors/mutt/ \
		ftp://ftp.parodius.com/pub/mutt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/ \
		ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/ 

DISTNAME=	mutt-${PORTVERSION}i
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	udo.schweigert@siemens.com

DIST_SUBDIR=    mutt
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-flock --disable-fcntl \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--sysconfdir=${PREFIX}/etc --enable-external-dotlock \
		--with-libiconv-prefix=${PREFIX}

.include <bsd.port.pre.mk>

USE_AUTOMAKE=	yes

.if defined(WITH_MUTT_COMPRESSED_FOLDERS) || defined(WITH_MUTT_NNTP) || \
		defined(WITH_MUTT_RU_PATCH) || defined(WITH_MUTT_QUOTE_PATCH)
PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		http://www2.mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${PATCH_VERSION}/ \
		ftp://ftp2.mutt.org.ua/pub/mutt/mutt-${PATCH_VERSION}/
.endif

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	@${PERL} -pi -e "s/^(ACLOCAL = ).+/\1${ACLOCAL}/; s/^(AUTOCONF = ).+/\1${AUTOCONF}/; \
		s/^(AUTOMAKE = ).+/\1${AUTOMAKE}/; s/^(AUTOHEADER = ).+/\1${AUTOHEADER}/" \
		${BUILD_WRKSRC}/Makefile

.if !defined(PATCH_VERSION)
PATCH_VERSION=	${PORTVERSION}
.endif

.if defined(PACKAGE_BUILDING)
WITH_MUTT_SSL=		yes
WITH_MUTT_SLANG=	yes
WITH_MUTT_IMAP=		yes
WITH_MUTT_POP=		yes
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_MUTT_HTML=	yes
.endif
.endif

.if defined(WITH_MUTT_SLANG)
USE_SLANG=	yes
.endif
.if defined(WITH_MUTT_NCURSES_PORT)
WITH_MUTT_NCURSES=	yes
.endif
.if defined(WITH_MUTT_NCURSES) && !defined(USE_SLANG)
USE_NCURSES=	yes
.endif
.if !defined(USE_SLANG) && !defined(WITHOUT_MUTT_SLANG) && !defined(USE_NCURSES)
USE_SLANG=	yes
.endif

.if defined(WITH_MUTT_SSL) && !defined(WITH_MUTT_IMAP) && \
	!defined(WITH_MUTT_POP)
WITH_MUTT_IMAP=	yes
.endif

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		giconv.2:${PORTSDIR}/converters/libiconv

.if defined(USE_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.elif defined(USE_NCURSES) && ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.endif
.if defined(WITH_MUTT_SSL)
USE_OPENSSL=	yes
.endif
.if defined(WITH_MUTT_HTML)
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif
.if defined(WITH_MUTT_NNTP)
BUILD_DEPENDS+=	${LOCALBASE}/news/bin/inews:${PORTSDIR}/news/inn-stable
pre-configure::
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-inews
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif

.if defined(WITH_MUTT_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(USE_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(USE_NCURSES) && ${OSVERSION} < 400000
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
.if defined(WITH_MUTT_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif
.if defined(WITH_MUTT_POP)
CONFIGURE_ARGS+=	--enable-pop
.endif
.if defined(WITH_MUTT_IMAP)
CONFIGURE_ARGS+=	--enable-imap
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--enable-imap \
			--with-sasl=${LOCALBASE}
WITH_MUTT_IMAP=                yes
.endif
.if defined(WITH_MUTT_POP_IMAP)
CONFIGURE_ARGS+=	--enable-pop --enable-imap
.endif

PATCH_DIST_STRIP=	-p1

.if defined(WITH_MUTT_COMPRESSED_FOLDERS)
PATCHFILES+=	patch-${PATCH_VERSION}.rr.compressed.gz
CONFIGURE_ARGS+=	--enable-compressed
.endif
.if defined(WITH_MUTT_NNTP)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.nntp.gz
CONFIGURE_ARGS+=	--enable-nntp
.endif
.if defined(WITH_MUTT_QUOTE_PATCH)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.initials.gz \
		patch-${PATCH_VERSION}.vvv.quote.gz
.endif
.if defined(WITH_MUTT_RU_PATCH)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.ru.gz
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		muttrc.5 mbox.5

post-patch::
	 @${PERL} -pi.fbsd -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc

pre-configure::
	@(cd ${WRKSRC}; ${ACLOCAL} -I m4)

.if !defined(NOPORTDOCS)
post-build:
	${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(WITH_MUTT_NNTP)
PLIST_SUB+=	SUB_NNTP=""
.else
PLIST_SUB+=	SUB_NNTP="@comment "
.endif
.if defined(WITH_MUTT_HTML)
PLIST_SUB+=	SUB_HTML=""
.if defined(WITH_MUTT_IMAP) || defined(WITH_MUTT_POP)
IMAP_OR_POP_SET:=	yes
.endif
.if defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_G=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_F=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_G=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_F=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_C=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_B=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_C=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_B=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_E=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_D=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_E=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_D=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_A=""
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_O=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_A=""
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_O=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_N=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_M=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_N=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_M=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_J=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_I=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_J=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_I=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_L=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_K=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_L=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_K=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_H=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_H=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH) && \
	!defined(IMAP_OR_POP_SET)
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.else # patches
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.endif
.else # HTML
PLIST_SUB+=	SUB_HTML="@comment "
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
.endif
.else 	# NOPORTDOCS
PLIST_SUB+=	SUB_HTML="@comment "
PLIST_SUB+=	SUB_NNTP="@comment "
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
PLIST_SUB+=	SUB_ADD_H="@comment "
PLIST_SUB+=	SUB_ADD_I="@comment "
PLIST_SUB+=	SUB_ADD_J="@comment "
PLIST_SUB+=	SUB_ADD_K="@comment "
PLIST_SUB+=	SUB_ADD_L="@comment "
PLIST_SUB+=	SUB_ADD_M="@comment "
PLIST_SUB+=	SUB_ADD_N="@comment "
PLIST_SUB+=	SUB_ADD_O="@comment "
post-patch::
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		../ABOUT-NLS ../contrib/language* \
		${PREFIX}/share/doc/mutt
.if defined(WITH_MUTT_NNTP)
	@cd ${WRKSRC} ; ${INSTALL_MAN} ChangeLog.nntp \
		${PREFIX}/share/doc/mutt
.endif
.if defined(WITH_MUTT_HTML)
	@${MKDIR} ${PREFIX}/share/doc/mutt/html && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
.endif
.endif
.if defined(WITH_MUTT_NNTP)
	@${ECHO} 
	@${ECHO} "------------------------------------------------"
	@${ECHO} "Be sure to define NNTPSERVER in your environment"
	@${ECHO} "and to be part of the group news in /etc/group"
	@${ECHO} "if you want to post news with mutt"
	@${ECHO} "------------------------------------------------"
	@${ECHO} 
.endif

.include <bsd.port.post.mk>
