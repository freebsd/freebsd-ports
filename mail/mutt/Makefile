# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	1.4.2.1
PORTREVISION=	2
CATEGORIES+=	mail ipv6
MASTER_SITES=	ftp://ftp.mutt.org/mutt/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/ \
		ftp://ftp.parodius.com/pub/mutt/
DISTFILES=	${DISTNAME}i${EXTRACT_SUFX}

PATCH_SITES=	http://www.mutt.org.ua/download/mutt-${PORTVERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${PORTVERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${PORTVERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${PORTVERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${PORTVERSION}/:vvv
PATCHFILES=	patch-${PORTVERSION}.rr.compressed.gz:vvv \
		patch-${PORTVERSION}.vvv.initials.gz:vvv
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	udo.schweigert@siemens.com
COMMENT?=	The Mongrel of Mail User Agents (part Elm, Pine, Mush, mh, etc.)

CONFLICTS=	mutt-devel-*

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support
.if defined(PACKAGE_BUILDING) && !defined (MUTT_LITE)
WITH_SLANG=	yes
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.endif
.if defined (MUTT_LITE)
WITH_SGML_DOCS:=no
.elif ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_SGML_DOCS?=yes
.endif

.if !defined (MUTT_LITE)
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
USE_ICONV=	yes
.if defined(WITHOUT_MUTT_ICONV)
.error the WITHOUT_MUTT_ICONV knob of the mutt port only works if \
	WITHOUT_NLS is also given
.endif
.elif !defined(WITHOUT_MUTT_ICONV) && !defined (MUTT_LITE)
USE_ICONV=	yes
.endif
.endif

.if defined(WITH_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.elif defined(WITH_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif
.if !defined (MUTT_LITE)
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif
.if defined(WITH_MUTT_XFACE)
PATCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/news/slrnface:extract
RUN_DEPENDS+=	slrnface:${PORTSDIR}/news/slrnface
.endif
.endif

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	19	# configure.in is patched by <PATCHFILES>
USE_AUTOCONF_VER=	259
USE_REINPLACE=	yes
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-pop --enable-imap --enable-flock --disable-fcntl \
		--with-ssl=${OPENSSLBASE} --sysconfdir=${PREFIX}/etc \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${DOCSDIR} --with-charmaps \
		--enable-compressed
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif
.if defined(WITH_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif
.if defined(WITHOUT_MUTT_ICONV) && defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-iconv
.else
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}
.endif
.if defined(WITH_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(WITH_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
MAN1=		mutt.1 mutt_dotlock.1
MAN5=		mbox.5 muttrc.5

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${REINPLACE_CMD} -e 's,pgp6,pgp,g' \
		${WRKSRC}/contrib/pgp6.rc
	@${REINPLACE_CMD} -E -e 's|@samplesdir@|${EXAMPLESDIR}|g' \
		${WRKSRC}/contrib/Makefile.in

.if defined(WITH_MUTT_XFACE)
post-patch::
	@${ECHO} "===>  Applying XFACE patch"
	slrnface_dir=`${FIND} ${PORTSDIR}/news/slrnface/work -type d \
			-name slrnface-\*`; \
	cd ${BUILD_WRKSRC}; ${PATCH} ${PATCH_ARGS} < $$slrnface_dir/mutt.patch
.endif

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	@${REINPLACE_CMD} -E -e "s|^(ACLOCAL = ).+|\1${ACLOCAL}|" \
			-e "s|^(AUTOCONF = ).+|\1${AUTOCONF}|" \
			-e "s|^(AUTOMAKE = ).+|\1${AUTOMAKE}|" \
			-e "s|^(AUTOHEADER = ).+|\1${AUTOHEADER}|" \
		${BUILD_WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-build:
	@${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/mutt.man
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/muttrc.man
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist.htmlfiles > ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
.endif
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Muttrc ${PREFIX}/etc/Muttrc.dist
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${DOCSDIR}
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m 0755 \
	    -d ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${DOCSDIR}
.endif
.endif

.if defined(WITH_MUTT_XFACE)
	@${ECHO} ""
	@${ECHO} "************************************************************"
	@${ECHO} "  To enable the XFACE support in mutt you also have to add"
	@${ECHO} "        set xface=yes"
	@${ECHO} "  to your ~/.muttrc"
	@${ECHO} "  Additional information is provided by news/slrnface"
	@${ECHO} "************************************************************"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
